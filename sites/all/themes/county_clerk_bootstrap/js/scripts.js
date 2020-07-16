(function ($, Drupal) {

  /**
   * Use this behavior as a template for custom Javascript.
   */
  $(window).on('load',function(){
    if($('#electionsModal').length != 0){
        $('#electionsModal').modal('show');

        $(document).keyup(function(e) {
            if (e.keyCode == 27) {
                $('#electionsModal').modal('hide');
            }
        });
    }
  });

  Drupal.behaviors.mobilenavBehavior = {
    attach: function (context, settings) {
      //hamburger nav
        $('.hamburger').on('click', function(){
          $(this).toggleClass('is-active');

          //show links
          $('nav.header').slideToggle();
          //slide body
          $('body , .canvas').toggleClass('menu-open');

          //$('.canvas').offcanvas('hide');
      });

      //dropdown nav
        $('.main-nav li.expanded').each(function(){
            $(this).on('click', function(){
                $(this).toggleClass('open');
            });
        });
    }
  };

  Drupal.behaviors.equalheights = {
    attach: function (context, settings) {

        equalheight = function(container){

        var currentTallest = 0,
             currentRowStart = 0,
             rowDivs = new Array(),
             $el,
             topPosition = 0;
         $(container).each(function() {

           $el = $(this);
           $($el).height('auto');
           topPosition = $el.position().top;

           if (currentRowStart !== topPosition) {
             for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
               rowDivs[currentDiv].height(currentTallest);
             }
             rowDivs.length = 0; // empty the array
             currentRowStart = topPosition;
             currentTallest = $el.height();
             rowDivs.push($el);
           } else {
             rowDivs.push($el);
             currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
          }
           for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
             rowDivs[currentDiv].height(currentTallest);
           }
         });
        };
        //equalheight('.election-blocks');
        $(window).load(function() {
            equalheight('.departments-pane .views-row');
            equalheight('.publications-grid .views-column');
            equalheight('.contact-body .views-column');
            equalheight('.jobs-grid .views-column');
            equalheight('.doeo-wrapper .official-box');
            //equalheight('.election-blocks');
            //equalheight('.page-service-directory-elected-officials .official-box');
        });


        $(window).resize(function(){
            equalheight('.publications-grid .views-column');
            equalheight('.departments-pane .views-row');
            equalheight('.contact-body .views-column');
            equalheight('.jobs-grid .views-column');
            //equalheight('.page-service-directory-elected-officials .official-box');
            equalheight('.tab-content .official-box');
            equalheight('.doeo-wrapper .official-box');
        });

        $('a[href="#edit-doeo"]').on('click', function(){
            //console.log('this');
            equalheight('.tab-content .official-box');
        });
    }
  };
  Drupal.behaviors.agencyAccordion = {
    attach: function (context, settings) {

    }
  };
    Drupal.behaviors.bannerAnalytics = {
        attach: function (context, settings) {
            $('.banner-carousel .views-row .active-banner').on('click', function(){
                var name = $(this).find('a').attr('title');
                var url = $(this).find('a').attr('href');
                var current = window.location.pathname;

                console.log(name, url, current);
            ga('send', {
                hitType: 'event',
                eventCategory: 'Banner Ad',
                eventAction: 'click',
                eventLabel: name
            });
            });
        }
    };
    Drupal.behaviors.searchAnalytics = {
        attach: function (context, settings) {
            //header search
            $('.search-bar .btn-info').on('click', function(){
                var name = $(this).find('a').attr('title');
                var url = $(this).find('a').attr('href');
                var current = window.location.pathname;
                ga('send', {
                    hitType: 'event',
                    eventCategory: 'Search',
                    eventAction: 'click',
                    eventLabel: 'Header Search'
                });
            });

            //paragraph search
            $('.para-search .btn-info').on('click', function(){
                var name = $(this).find('a').attr('title');
                var url = $(this).find('a').attr('href');
                var current = window.location.pathname;
                ga('send', {
                    hitType: 'event',
                    eventCategory: 'Search',
                    eventAction: 'click',
                    eventLabel: 'Hero Search'
                });
            });
        }
    };

  Drupal.behaviors.copyText = {
      attach: function (context, settings){
          if($('.media-library .views-widget-filter-combine .form-text').val() !== ''){
              //console.log($(".views-widget-filter-keys .form-text").val());
            $('.fake-input').val($(".views-widget-filter-combine .form-text").val());
          }
        $(".fake-input").keyup(function(e){
            $(".media-library .views-widget-filter-combine .form-text").val($(this).val());

             if(e.keyCode == 13){
                //console.log('button');
                $('.media-library .views-exposed-widget .btn-info').trigger('click');

                //$(this).trigger("enterKey");
            }
        });
        $('.btn-fake').on('click', function(){
            $('.media-library .views-exposed-widget .btn-info').trigger('click');
        });
        var title = jQuery('.node-type-jobs h1.page-header').text();
        console.log(title);
        jQuery('.app-jobname').val(title)
      }
  };
    Drupal.behaviors.youtube = {
      attach:function (context, settings){
          var clickTap = $.support.touch ? "tap" : "click";

          //starts youtube video
          $('.media-library.grid .views-row, .media-block-container .views-row').each(function(){
                //making sure no one right clicks and opens bad url
                $('.vid_overlay', this).find('a').attr('href', '#');
                $('.vid_overlay', this).on(clickTap, function(ev) {
                $(this).fadeOut('slow');
                $(this).parent().find(".media-youtube-player")[0].src += "&autoplay=1";
                    ev.preventDefault();

              });
          });

          $("a[href^='/video']").on('click', function(){
              var link = $(this).attr('href');
              console.log(link);
              $(this).attr('href', '#');
            window.open( link, '_blank');
            location.reload();
          });
      }
  }
  Drupal.behaviors.searchButton = {
    attach: function (context, settings) {
        $('.search-icon div').on('click', function(){
            //console.log('clicked');
           $('.search-bar').toggleClass('active');
           if($('.search-bar').hasClass('active')){
                $('.search-bar').prepend('<div class="close">X</div>');
            } else {
                $('.close').remove();
            }
        });

        $('.search-bar').on('click',  '.close', function(){
            //console.log('clicking here');
            $('.search-bar').removeClass('active');
        });
    }
  };

    Drupal.behaviors.publication = {
        attach: function (context, settings) {


        }
    };
  Drupal.behaviors.slick = {
    attach: function (context, settings) {
      $('.banner-carousel .view-content').slick({
        centerMode: true,
        dots: true,
        centerPadding: '10px',
        slidesToShow: 2,
        slidesToScroll: 3,
        variableWidth: true,
        infinite: true,
        responsive: [
          {
            breakpoint: 768,
            settings: {
            arrows: false,
            centerMode: true,
            centerPadding: '20px',
            slidesToShow: 1,
            variableWidth: true
            }
          },
          {
            breakpoint: 480,
            settings: {
            arrows: false,
            centerMode: true,
            centerPadding: '20px',
            slidesToShow: 1,
            variableWidth: true
            }
          }
        ]
      });
    }
  };
  Drupal.behaviors.misc = {
      attach:function(context, settings){
          $('.docs .field-name-field-media-contact h2 a').attr('href', '');


          $('.view-departments a').each(function() {
                var $this = $(this);
                if($this.html().replace(/\s|&nbsp;/g, '').length == 0)
                    $this.remove();
            });
          $('.view-departments .views-row').each(function(){
              links = $(this).find('.dept-title-icon a').attr('href');
              $(this).find('.icon-type a').attr('href', links);
          });

          $('.para-search input, .search-bar input, .pane-views-exp-primary-search-view-page-1 input').attr('placeholder', 'Search For..');

          if($('.primary-search .search-block').length != '' && $(window).width() >= 768){
            var offset = $('.primary-search .search-block').offset();
            var h1 = offset.top - 66;
            $('.view-search .region-sidebar-second').css('margin-top', h1+'px');
          }


    }
  };
  Drupal.behaviors.jumplinks = {
      attach:function(context, settings){
            /*$('#voter-api-address-search-form #jump').each(function(){
                $(this).on('click', function(){
                    //$(this).attr()
                   // window.location
                });
            });*/
      }
  };

Drupal.behaviors.doeo = {
  attach: function (context, settings) {
    var width = $(window).width();
    function scrollToAnchor(aid){
        var aTag = $("#"+ aid +"");
        $('html,body').animate({scrollTop: aTag.offset().top},'slow');
    }

    $("#edit-search-needle").keyup(function(e){
        //$(".media-library .views-widget-filter-combine .form-text").val($(this).val());
         if(e.keyCode == 13){
            console.log('button');
            $('.button-wrapper .btn-info').trigger('click');
        }
    });

      $('.button-wrapper .btn-info').bind('click', function(){
        $( document ).ajaxComplete(function() {
            console.log('this');
            equalheight('.doeo-wrapper .official-box');
        });

      });
      $('.doeo-button-wrapper .doeo-options').each(function(){
          $(this).on('click', function(){
              $('.doeo-options').removeClass('active');
              $(this).addClass('active');
              //$(this).addClass('active');

              if($(this).hasClass('option-2')){
                  console.log('option2');
                  $('.doeo-wrap').removeClass('active');
                  $('.doeo-wrap.levels').addClass('active');
              }else if($(this).hasClass('option-1')){
                  $('.doeo-wrap').removeClass('active');
                  $('.doeo-wrap.address').addClass('active');
              }else{
                  $('.doeo-wrap').removeClass('active');
                  $('.doeo-wrap.officials').addClass('active');
              }
          });
      });

      if(width <= 768){
        $('.doeo-wrap').on('click', function(){
           if(!$(this).hasClass('active')){
                $('.doeo-wrap').removeClass('active');
                $(this).addClass('active');
           }
        });
        /*$( ".doeo-wrap .btn" ).bind( "click", function() {
                //console.log( "User clicked on 'foo.'" );
                scrollToAnchor('doeo-wrappers');
            });*/
        }
      $(window).on("resize", function(){
        //console.log('resizinf');

        if(width <= 768){
            $('.doeo-wrap').on('click', function(){
               if(!$(this).hasClass('active')){
                   $('.doeo-wrap').removeClass('active');
                    $(this).addClass('active');
               }
                console.log('stuff');
            });
            /*$( ".doeo-wrap .btn" ).bind( "click", function() {
                //console.log( "User clicked on 'foo.'" );
                //scrollToAnchor('doeo-wrappers');
              });*/
        }
      });
  }
};
  Drupal.behaviors.logoshrink = {
      attach:function(context, settings){
        function checkScroll(){
            var startY = $('.navbar').height() - 40; //The point where the navbar changes in px
            var filterY = $('.navbar').height() + 110;
            //console.log(filterY);
                //console.log(startY);
                //console.log($(window).scrollTop());
            if($(window).scrollTop() > startY){
                //$('.scrollTop').addClass('active');
                $('.canvas').addClass("scrolled");
                //$('.view-search .region-sidebar-second').addClass('active');
            }else{
                //$('.scrollTop').removeClass('active');
                $('.canvas').removeClass("scrolled");
                //$('.view-search .region-sidebar-second').removeClass('active');
            }
        }

          /*$('.scrollTop ').on('click', function(){
              console.log('clicked');
              $("html, body").animate({
                    scrollTop: 0
                }, 600);
                return false;
          });*/
	if($('.navbar').length > 0){
	    $(window).on("scroll load resize", function(){
	        checkScroll();
	    })};

        /*
          window.setInterval(function(){
              if($('.map-load').is(':empty')){
                //console.log('this is running');

              } else{
                  //console.log('not');
              }
          }, 5000);
          */


	//}
      }
  };

})(jQuery, Drupal);
