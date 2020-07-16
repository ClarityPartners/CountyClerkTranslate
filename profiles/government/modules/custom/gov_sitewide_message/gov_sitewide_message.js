(function ($) {
    jQuery.fn.exists = function () {
        return this.length > 0;
    }
    Drupal.behaviors.sitewidemessage = {
        attach: function (context, settings) {
            $(document).ready(function () {
                var text = '<div id="sitewidemessage-wrapper">';
                text += '<div id="sitewidemessage-container">';
                text += '<div id="sitewidemessage-content">' + settings.sitewidemessage.message;
                text += '<a href="' + settings.sitewidemessage.link + '" title="' + settings.sitewidemessage.link_text + '" target="' + settings.sitewidemessage.link_target + '" id="sitewidemessage-logo">' + settings.sitewidemessage.link_text + '</a></div>';
                text += '<a href="#close" id="sitewidemessage-close">Close</a>';
                text += '<div id="sitewidemessage-shadow"></div></div>';
                text += '</div><a href="#close" id="sitewidemessage-open" style="">Open</a>';
                $('body').prepend(text);
                $('body').css({"padding-top": "30px"});
                $('div#sitewidemessage-container').css({"background-color": settings.sitewidemessage.color_bg});
                $('a#sitewidemessage-open').css({"background-color": settings.sitewidemessage.color_bg});
                $('div#sitewidemessage-container').css({"color": settings.sitewidemessage.color_text});
                $('div#sitewidemessage-container a#sitewidemessage-logo').css({"color": settings.sitewidemessage.color_link});
                if (settings.sitewidemessage.autohide) {
                    var seconds = !isNaN(settings.sitewidemessage.autohide_seconds) ? settings.sitewidemessage.autohide_seconds * 1000 : 5000;
                    setting_timeout(seconds);
                }
                $("#sitewidemessage-open").click(function () {
                    open_sitewide();
                });
                $("#sitewidemessage-close").click(function () {
                    close_sitewide();
                });
            });
            function setting_timeout(seconds) {
                return setTimeout(function () {
                    close_sitewide();
                }, seconds);
            }

            function close_sitewide() {
                if (!$('#toolbar').exists()) {
                    $('body').animate({'padding-top': '0'}, 'slow');
                }
                $("#sitewidemessage-wrapper").slideUp();
                $("#sitewidemessage-open").slideDown();
            }

            function open_sitewide() {
                if (!$('#toolbar').exists()) {
                    $('body').animate({'padding-top': '30'}, 'slow');
                }
                $("#sitewidemessage-wrapper").slideDown();
                $("#sitewidemessage-open").slideUp();
            }
        }
    }
})(jQuery);