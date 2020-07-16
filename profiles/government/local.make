; governement make file for local development
core = "7.x"
api = "2"

projects[drupal][version] = "7.x"
; include the d.o. profile base
includes[] = "drupal-org.make"

projects[gov_bootstrap][version] = "7.x-1.0" ;
projects[gov_bootstrap][subdir] = "custom"

; +++++ Libraries +++++

; jquery.blockui
libraries[jquery.blockui][directory_name] = "jquery.blockui"
libraries[jquery.blockui][type] = "library"
libraries[jquery.blockui][destination] = "libraries"
libraries[jquery.blockui][download][type] = "get"
libraries[jquery.blockui][download][url] = "" ; TODO add download URI

; fontawesome
libraries[fontawesome][directory_name] = "fontawesome"
libraries[fontawesome][type] = "library"
libraries[fontawesome][destination] = "libraries"
libraries[fontawesome][download][type] = "get"
libraries[fontawesome][download][url] = "" ; TODO add download URI

; imagesloaded
libraries[imagesloaded][directory_name] = "imagesloaded"
libraries[imagesloaded][type] = "library"
libraries[imagesloaded][destination] = "libraries"
libraries[imagesloaded][download][type] = "get"
libraries[imagesloaded][download][url] = "" ; TODO add download URI

; jreject
libraries[jreject][directory_name] = "jreject"
libraries[jreject][type] = "library"
libraries[jreject][destination] = "libraries"
libraries[jreject][download][type] = "get"
libraries[jreject][download][url] = "" ; TODO add download URI

; html_encoder
libraries[html_encoder][directory_name] = "html_encoder"
libraries[html_encoder][type] = "library"
libraries[html_encoder][destination] = "libraries"
libraries[html_encoder][download][type] = "get"
libraries[html_encoder][download][url] = "" ; TODO add download URI

; jquery.cycle
libraries[jquery.cycle][directory_name] = "jquery.cycle"
libraries[jquery.cycle][type] = "library"
libraries[jquery.cycle][destination] = "libraries"
libraries[jquery.cycle][download][type] = "get"
libraries[jquery.cycle][download][url] = "" ; TODO add download URI

; tinymce
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][type] = "library"
libraries[tinymce][destination] = "libraries"
libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "" ; TODO add download URI

; iCalcreator
libraries[iCalcreator][directory_name] = "iCalcreator"
libraries[iCalcreator][type] = "library"
libraries[iCalcreator][destination] = "libraries"
libraries[iCalcreator][download][type] = "get"
libraries[iCalcreator][download][url] = "" ; TODO add download URI

