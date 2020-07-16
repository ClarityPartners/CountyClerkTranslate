(function($) {
  var directionsDisplay;
  var map;
  var rendered = {};
  rendered.polling = false;
  rendered.earlyvoting = false;
  rendered.voterinfo = true;
  rendered.mailballot = true;
  rendered.provisional = true;
  rendered.ballot = true;
  rendered.doeo = true;
  Drupal.voterApi = {};

  Drupal.voterApi.initializeMap = function(elementPrefix) {
    directionsDisplay = new google.maps.DirectionsRenderer();
    var chicago = new google.maps.LatLng(41.850033, -87.6500523);
    var mapOptions = {
      zoom: 15,
      minZoom: 10,
      center: chicago
    };
    // Do polling map.
    var mapselector = '#' + elementPrefix + 'Map';
    var directionsSelector = '#' + elementPrefix + 'DirectionsPanel';
    var $mapDiv = $(mapselector).get(0);
    var $directionsDiv = $(directionsSelector).get(0);
    map = new google.maps.Map($mapDiv, mapOptions);
    directionsDisplay.setMap(map);
    directionsDisplay.setPanel($directionsDiv);
    Drupal.voterApi.calculateRoute(elementPrefix);
  };

  Drupal.voterApi.calculateRoute = function(elementPrefix) {
    var directionsService = new google.maps.DirectionsService();
    var startSelector = '.voterAddress';
    var destinationSelector = '#' + elementPrefix + 'Address';
    var startElement = $(startSelector).first();
    var start = startElement.text();
    var end = $(destinationSelector).text();
    var request = {
      origin: start,
      destination: end,
      travelMode: 'DRIVING'
    };
    directionsService.route(request, function (response, status) {
      if (status === 'OK') {
        directionsDisplay.setDirections(response);
        // google.maps.event.trigger(map, 'resize');
      }
    });

    google.maps.event.addListener(directionsDisplay, "directions_changed", function () {

    });
  };

  Drupal.behaviors.voterApi = {
    attach: function (context, settings) {
      var clickedTab = 'none';
      if (typeof settings.voterApi != "undefined") {
        clickedTab = settings.voterApi.clickedTab;
        console.log(clickedTab);
      }

      /////////////////////
      //  MAP FUNCTIONS  //
      /////////////////////
      if (typeof settings.voterApi != "undefined" && settings.voterApi.pollingPlaceFound === 1) {
        var gmapsScript = 'https://maps.googleapis.com/maps/api/js?key=AIzaSyCprWFwbh0Elnz-I84HHOvFcEesFTGpQaA';
        $.getScript(gmapsScript, function () {
          console.log('gmaps script loaded');
        }).done(function() {
          $.each(rendered, function (tabName, value) {
            console.log(tabName);
            if (clickedTab === tabName && value === false) {
              rendered[tabName] = true;
              Drupal.voterApi.initializeMap(tabName);
            }
          });
        });
        $('.vertical-tab-button', context).click(function () {
          var clickedId = $(this).find('a').attr('href').substring(6).replace('-', '');
          if (rendered[clickedId] === false) {
            rendered[clickedId] = true;
            Drupal.voterApi.initializeMap(clickedId);
          }
        });
      }

      ///////////////////////
      //  PRINT FUNCTIONS  //
      ///////////////////////

      $(':checkbox').click(function() {
          console.log(this);
        if ($(this).is(":checked")) {
          $(this).closest('.candidate-row').removeClass('no-print');
          $(this).closest('.race').removeClass('no-print');
          this.setAttribute('checked', '');
          this.checked = true;
        } else {
          $(this).closest('.candidate-row').addClass('no-print');
          this.removeAttribute('checked');
          this.checked = false;
        }
        return(true);
      });

      var printCss = '/sites/all/modules/custom/voter_api/css/print2.css';

      var clickTap = $.support.touch ? "tap" : "click";

      $('#print-doeo-button', context).off().on(clickTap,function(){
      //$('#print-doeo-button', context).click(function(e) {
        $('.doeo-wrapper').print({
          stylesheet: printCss,
          globalStyles: false,
          noPrintSelector:".no-print",
        });
      });
      $('#print-polling-button', context).off().on(clickTap,function(){
        $('.pollingBox').print({
          globalStyles: true,
          mediaPrint: false,
          stylesheet: printCss,
          noPrintSelector:".no-print",
        });
      });
      $('#print-early-voting-button', context).off().on(clickTap,function(){
        $('.earlyVotingBox').print({
          stylesheet: printCss,
          noPrintSelector:".no-print",
        });
      });
      $('#print-my-ballot', context).off().on(clickTap,function(){
        $('#printable-ballot').print({
          stylesheet: printCss,
          noPrintSelector:".no-print",
          globalStyles: false,
        });
      });
      $('#print-whole-ballot', context).off().on(clickTap,function(){
        // There is no .yes-print class, so all elements will print.
        $('#printable-ballot').print({
          globalStyles: false,
          stylesheet: printCss,
          noPrintSelector:".yes-print"
        });
      });
      $('#print-whole-ballot-2', context).off().on(clickTap,function(){
        // There is no .yes-print class, so all elements will print.
        $('#printable-ballot').print({
          globalStyles: false,
          stylesheet: printCss,
          noPrintSelector:".yes-print"
        });
      });
      /******Modal******/
      /*$('.candidate-row #canstate').on('click', function(){
        console.log();
        $(this).find('#statementDiv').modal('show');
      });*/
      $('.candidate-row').each(function(){
        $('#canstate', this).on('click', function(){
          console.log($(this).text());
          $(this).parent().parent().find('#statementDiv').modal('show');
        });
      });
      ////////////////////
      // EMAIL FUNCTION //
      ////////////////////
      // $('#email-my-ballot', context).click(function() {
      //   var races = $('#printable-ballot').text();
      //   $(this).attr('href', 'mailto:?subject=Cook County Ballot&body='+races);
      // });
    }
  };

})(jQuery);
