(function($) {

  // Behavior to load FlexSlider
  Drupal.behaviors.flexslider = {
    attach: function(context, settings) {
      var sliders = [];
      if ($.type(settings.flexslider) !== 'undefined' && $.type(settings.flexslider.instances) !== 'undefined') {

        for (id in settings.flexslider.instances) {

          if (settings.flexslider.optionsets[settings.flexslider.instances[id]] !== undefined) {
            if (settings.flexslider.optionsets[settings.flexslider.instances[id]].asNavFor !== '') {
              // We have to initialize all the sliders which are "asNavFor" first.
              _flexslider_init(id, settings.flexslider.optionsets[settings.flexslider.instances[id]], context);
            } else {
              // Everyone else is second
              sliders[id] = settings.flexslider.optionsets[settings.flexslider.instances[id]];
            }
          }
        }
      }
      // Slider set
      for (id in sliders) {
        _flexslider_init(id, settings.flexslider.optionsets[settings.flexslider.instances[id]], context);
      }
    }
  };

  /**
   * Initialize the flexslider instance
   */

function _flexslider_init(id, optionset, context) {
  //If it is a featured media slider, custom init code to make the
  //thumbnails a carousel.
  if ($('#' + id).parent().hasClass('featured-media-slider')){
    $('#' + id, context).once('flexslider', function() {

      $(this).find('ul.slides > li > *').removeAttr('width').removeAttr('height');
      var slideshow = $('#' + id);
      var thumbs = $('#' + id + '-thumbnails');
      $(this).next().flexslider({
        animation: "slide",
        controlNav: false,
        animationLoop: false,
        slideshow: false,
        itemWidth: 210,
        itemMargin: 5,
        asNavFor: $(this)
      });
     
      $(this).flexslider({
        animation: "slide",
        controlNav: false,
        animationLoop: false,
        slideshow: false,
        sync: $(this).next()
      });
    });
  } else {
    $('#' + id, context).once('flexslider', function() {
    // Remove width/height attributes
    // @todo load the css path from the settings
    $(this).find('ul.slides > li > *').removeAttr('width').removeAttr('height');

    if (optionset) {
      // Add events that developers can use to interact.
      $(this).flexslider($.extend(optionset, {
        start: function(slider) {
          slider.trigger('start');
        },
        before: function(slider) {
          slider.trigger('before');
        },
        after: function(slider) {
          slider.trigger('after');
        },
        end: function(slider) {
          slider.trigger('end');
        },
        added: function(slider) {
          slider.trigger('added');
        },
        removed: function(slider) {
          slider.trigger('removed');
        }
      }));
    } else {
      $(this).flexslider();
    }
    $(this).flexslider();
  });
  }
}

}(jQuery));
