var that = this
function __skpm_run(key, context) {
  that.context = context

  var exports = /******/ (function(modules) {
    // webpackBootstrap
    /******/ // The module cache
    /******/ var installedModules = {} // The require function
    /******/
    /******/ /******/ function __webpack_require__(moduleId) {
      /******/
      /******/ // Check if module is in cache
      /******/ if (installedModules[moduleId]) {
        /******/ return installedModules[moduleId].exports
        /******/
      } // Create a new module (and put it into the cache)
      /******/ /******/ var module = (installedModules[moduleId] = {
        /******/ i: moduleId,
        /******/ l: false,
        /******/ exports: {},
        /******/
      }) // Execute the module function
      /******/
      /******/ /******/ modules[moduleId].call(
        module.exports,
        module,
        module.exports,
        __webpack_require__
      ) // Flag the module as loaded
      /******/
      /******/ /******/ module.l = true // Return the exports of the module
      /******/
      /******/ /******/ return module.exports
      /******/
    } // expose the modules object (__webpack_modules__)
    /******/
    /******/
    /******/ /******/ __webpack_require__.m = modules // expose the module cache
    /******/
    /******/ /******/ __webpack_require__.c = installedModules // define getter function for harmony exports
    /******/
    /******/ /******/ __webpack_require__.d = function(exports, name, getter) {
      /******/ if (!__webpack_require__.o(exports, name)) {
        /******/ Object.defineProperty(exports, name, {
          /******/ configurable: false,
          /******/ enumerable: true,
          /******/ get: getter,
          /******/
        })
        /******/
      }
      /******/
    } // getDefaultExport function for compatibility with non-harmony modules
    /******/
    /******/ /******/ __webpack_require__.n = function(module) {
      /******/ var getter =
        module && module.__esModule
          ? /******/ function getDefault() {
              return module['default']
            }
          : /******/ function getModuleExports() {
              return module
            }
      /******/ __webpack_require__.d(getter, 'a', getter)
      /******/ return getter
      /******/
    } // Object.prototype.hasOwnProperty.call
    /******/
    /******/ /******/ __webpack_require__.o = function(object, property) {
      return Object.prototype.hasOwnProperty.call(object, property)
    } // __webpack_public_path__
    /******/
    /******/ /******/ __webpack_require__.p = '' // Load entry module and return exports
    /******/
    /******/ /******/ return __webpack_require__((__webpack_require__.s = 0))
    /******/
  })(
    /************************************************************************/
    /******/ [
      /* 0 */
      /***/ function(module, exports, __webpack_require__) {
        'use strict'

        Object.defineProperty(exports, '__esModule', {
          value: true,
        })
        exports.exportJSON = exports.exportSass = exports.promptSaveLocation = undefined

        var _sketch = __webpack_require__(1)

        var _sketch2 = _interopRequireDefault(_sketch)

        function _interopRequireDefault(obj) {
          return obj && obj.__esModule ? obj : { default: obj }
        }

        function _defineProperty(obj, key, value) {
          if (key in obj) {
            Object.defineProperty(obj, key, {
              value: value,
              enumerable: true,
              configurable: true,
              writable: true,
            })
          } else {
            obj[key] = value
          }
          return obj
        }

        var promptSaveLocation = (exports.promptSaveLocation = function promptSaveLocation(
          extension
        ) {
          var saveDialog = NSSavePanel.savePanel()

          saveDialog.setNameFieldStringValue('variables')

          saveDialog.setAllowedFileTypes([extension])

          saveDialog.setAllowsOtherFileTypes(false)

          saveDialog.setExtensionHidden(false)

          if (saveDialog.runModal() === NSOKButton) return saveDialog.URL()

          return null
        })

        var run = function run(accumulator, extension, foldFunction) {
          var stringify =
            arguments.length > 3 && arguments[3] !== undefined
              ? arguments[3]
              : function(str) {
                  return str
                }

          var document = _sketch2['default'].getSelectedDocument()
          var selectedLayers = document.selectedLayers

          var selectedCount = selectedLayers.length

          if (selectedCount === 0) {
            _sketch2['default'].UI.message('No layers are selected. 😕')
          } else {
            var url = promptSaveLocation(extension)

            if (url) {
              var variables = selectedLayers.reduce(foldFunction, accumulator)

              var path = url.path()
              var content = NSString.stringWithString(stringify(variables))

              content.writeToFile_atomically_encoding_error_(
                path,
                true,
                NSUTF8StringEncoding,
                null
              )

              _sketch2['default'].UI.message('Tokens Successfully Exported. 🎉')
            }
          }
        }

        var foldLayerToSassVar = function foldLayerToSassVar(acc, layer) {
          if (layer.type === 'Text') {
            return (
              String(acc) +
              '$' +
              String(layer.name) +
              ': ' +
              String(layer.style.fontSize) +
              'px;\n'
            )
          }

          if (layer.type === 'Rectangle') {
            return (
              String(acc) +
              '$' +
              String(layer.name) +
              ': ' +
              String(layer.style.fills[0].color.slice(0, 7)) +
              ';\n'
            )
          }

          return acc
        }

        var foldLayerToJsonKV = function foldLayerToJsonKV(acc, layer) {
          if (layer.type === 'Text') {
            return Object.assign(
              {},
              acc,
              _defineProperty(
                {},
                layer.name,
                String(layer.style.fontSize) + 'px'
              )
            )
          }

          if (layer.type === 'ShapePath') {
            return Object.assign(
              {},
              acc,
              _defineProperty(
                {},
                layer.name,
                layer.style.fills[0].color.slice(0, 7)
              )
            )
          }

          return acc
        }

        var exportSass = (exports.exportSass = function exportSass() {
          run('', 'scss', foldLayerToSassVar)
        })

        var exportJSON = (exports.exportJSON = function exportJSON() {
          run({}, 'json', foldLayerToJsonKV, JSON.stringify)
        })

        /***/
      },
      /* 1 */
      /***/ function(module, exports) {
        module.exports = require('sketch')

        /***/
      },
      /******/
    ]
  )
  if (key === 'default' && typeof exports === 'function') {
    exports(context)
  } else {
    exports[key](context)
  }
}
that['exportSass'] = __skpm_run.bind(this, 'exportSass')
that['onRun'] = __skpm_run.bind(this, 'default')
that['exportJSON'] = __skpm_run.bind(this, 'exportJSON')
