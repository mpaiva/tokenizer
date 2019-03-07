import sketch from 'sketch'
// documentation: https://developer.sketchapp.com/reference/api/

export default function() {
  const document = sketch.getSelectedDocument()
  const selectedLayers = document.selectedLayers
  const selectedCount = selectedLayers.length
  
  if (selectedCount === 0) {
    sketch.UI.message('No layers are selected. 😕')
  } else {
    selectedLayers.forEach(function (layer) {
     if (layer.type === 'Text') {
       sketch.UI.message('$' + layer.name + ': ' + layer.style.fontSize + 'px')
     } else {
       sketch.UI.message('$' + layer.name + ': ' + layer.style.fills[0].color.slice(0, 7))
     }
    })
  }
}



