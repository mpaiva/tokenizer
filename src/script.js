import sketch from 'sketch'

export const promptSaveLocation = (extension) => {
  const saveDialog = NSSavePanel.savePanel()

  saveDialog.setNameFieldStringValue("variables")

  saveDialog.setAllowedFileTypes([extension])

  saveDialog.setAllowsOtherFileTypes(false);

  saveDialog.setExtensionHidden(false);
  
  // If the users selects 'OK', return the location they specified
  if (saveDialog.runModal() == NSOKButton)
    return saveDialog.URL()

  // Otherwise return nothing
  return nil
}

export const exportSass = () => {
  const document = sketch.getSelectedDocument()
  const selectedLayers = document.selectedLayers
  const selectedCount = selectedLayers.length
  
  if (selectedCount === 0) {
    sketch.UI.message('No layers are selected. 😕')
  } else {
    const url = promptSaveLocation("scss")

    if (url) {
      const variables = selectedLayers.reduce((acc, layer) => {
       if (layer.type === 'Text') {
         return acc + '$' + layer.name + ': ' + layer.style.fontSize + 'px;\n'
       } else {
         return acc + '$' + layer.name + ': ' + layer.style.fills[0].color.slice(0, 7) + ';\n'
       }
      }, '')

      const path = url.path();
      const content = NSString.stringWithString(variables);

      content.writeToFile_atomically_encoding_error_(
        path, true, NSUTF8StringEncoding, null
      )

      sketch.UI.message('Sass variables successfully saved. 🎉')
    }
  }
}
