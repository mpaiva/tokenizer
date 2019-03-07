import sketch from 'sketch'

const promptSaveLocation = extension => {
  const saveDialog = NSSavePanel.savePanel()

  saveDialog.setNameFieldStringValue('variables')

  saveDialog.setAllowedFileTypes([extension])

  saveDialog.setAllowsOtherFileTypes(false)

  saveDialog.setExtensionHidden(false)

  if (saveDialog.runModal() === NSOKButton) return saveDialog.URL()

  return null
}

const run = (accumulator, extension, foldFunction, stringify = str => str) => {
  const document = sketch.getSelectedDocument()
  const { selectedLayers } = document
  const selectedCount = selectedLayers.length

  if (selectedCount === 0) {
    sketch.UI.message('No layers are selected. 😕')
  } else {
    const url = promptSaveLocation(extension)

    if (url) {
      const variables = selectedLayers.reduce(foldFunction, accumulator)

      const path = url.path()
      const content = NSString.stringWithString(stringify(variables))

      content.writeToFile_atomically_encoding_error_(
        path,
        true,
        NSUTF8StringEncoding,
        null
      )

      sketch.UI.message('Tokens Successfully Exported. 🎉')
    }
  }
}

const makeTextSassVars = (acc, layer) => `${acc}
$${layer.name}-font-size: ${layer.style.fontSize}px;
$${layer.name}-font-family: ${layer.style.fontFamily};
$${layer.name}-font-weight: ${layer.style.fontWeight}px;
$${layer.name}-color: ${layer.style.textColor};
$${layer.name}-text-transform: ${layer.style.textTransform};`

const foldLayerToSassVar = (acc, layer) => {
  if (layer.type === 'Text') {
    return makeTextSassVars(acc, layer)
  }

  if (layer.type === 'ShapePath') {
    return `${acc}$${layer.name}: ${layer.style.fills[0].color.slice(0, 7)};\n`
  }

  return acc
}

const foldLayerToJsonKV = (acc, layer) => {
  if (layer.type === 'Text') {
    return {
      ...acc,
      [`${layer.name}-font-size`]: `${layer.style.fontSize}px`,
      [`${layer.name}-font-family`]: `${layer.style.fontFamily}`,
      [`${layer.name}-font-weight`]: `${layer.style.fontWeight}px`,
      [`${layer.name}-color`]: `${layer.style.textColor}`,
      [`${layer.name}-text-transform`]: `${layer.style.textTransform}`,
    }
  }

  if (layer.type === 'ShapePath') {
    return {
      ...acc,
      [layer.name]: layer.style.fills[0].color.slice(0, 7),
    }
  }

  return acc
}

export const exportSass = () => {
  run('', 'scss', foldLayerToSassVar)
}

export const exportJSON = () => {
  run({}, 'json', foldLayerToJsonKV, JSON.stringify)
}
