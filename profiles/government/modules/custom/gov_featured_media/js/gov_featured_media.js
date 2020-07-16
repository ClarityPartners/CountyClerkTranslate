(function($) {

  //Watches for the flexslider active class change
  //And pauses all videos contained in a flexslider slide that are not active.
  Drupal.behaviors.pauseVideo = {
    attach: function(context, settings){

      var $div = jQuery.makeArray($(".block-fieldblock .flexslider .slides li"));
      var observer = new MutationObserver(function(mutations) {
          mutations.forEach(function(mutation) {
              if (mutation.attributeName === "class") {
                var attributeValue = $(mutation.target).prop(mutation.attributeName);
                $('.block-fieldblock .flexslider .slides li:not(.flex-active-slide) .fluid-width-video-wrapper').each(function(index){
                  var iframe = $(this)[0].getElementsByTagName("iframe")[0].contentWindow;
                  iframe.postMessage('{"event":"command","func":"pauseVideo","args":""}', '*');
                });
              }
          });
      });

      $div.forEach(function(slide) {
        observer.observe(slide,  {
          attributes: true
        });
      });
    }
  };

}(jQuery));