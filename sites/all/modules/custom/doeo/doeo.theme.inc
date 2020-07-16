<?php

/**
 * Themes the output for a single elected official.
 *
 * @param $data
 *
 * @return string
 */
function doeo_theme_elected_official($data) {
  $official = $data['elected_official'];
  $appointed = '';
  if ( $official['Appointed'] == TRUE ){
    $appointed = ' Appointed';
  } else {
    $appointed = $official['LastElected'];
  }
  $suffix = '';
  if($official['Suffix'] != ''){
    $suffix = ', '.$official['Suffix'];
  }

  $html =  '<div class="official-box">';
  if($official['Nickname'] != ''){
    $html .=   '<div class="official-title">' . $official['Office'] . ', ' . $official['Jurisdiction'] . ' - ' . $official['FirstName'] . ' ' . '"'.$official['Nickname'].'"' . ' ' . $official['MiddleName'] . ' ' . $official['LastName'] . $suffix .'</div>';
  } else {
    $html .=   '<div class="official-title">' . $official['Office'] . ', ' . $official['Jurisdiction'] . ' - ' . $official['full_name'] . $suffix .'</div>';
  }
  $html .=   '<div class="official-body">';
  $html .=     '<div class="election-dates">';
  $html .=       '<div class="box"><div class="elected-label">Last Elected</div><div class="elected-detail">' . $appointed . '</div></div>';
  $html .=       '<div class="box"><div class="next-election-label">Next Election</div><div class="next-election-detail">' . $official['NextElection'] . '</div></div>';
  $html .=       '<div class="box"><div class="term-label">Term</div><div class="term-detail">' . $official['TermAppointed'] . ' years</div></div>';
  $html .=     '</div>';
  $html .=     '<div class="official-addresses">';
  foreach ($official['Addresses'] as $address) {
    $phone = "(".substr($address['Phone'],0,3).") ".substr($address['Phone'],3,3)."-".substr($address['Phone'],6);
    $fax = "(".substr($address['Fax'],0,3).") ".substr($address['Fax'],3,3)."-".substr($address['Fax'],6);
    $html .=     '<div class="box"><div class="address-label">Address</div><div class="address-detail">' . $address['Address1'] . '<br/>';

    if (!empty($address['Address2'])) {
      $html .= $address['Address2'] . '<br/>';
    }
    $html .= $address['City'] . ', ' . $address['State'] . ' ' . $address['Zip'] . '</div></div>';
    if (!empty($address['Phone'])) {
      $html .=   '<div class="box"><div class="phone-label">Phone</div><div class="phone-detail">' . $phone . '</div></div>';
    }
    if (!empty($address['Fax'])) {
      $html .=   '<div class="box"><div class="fax-label">Fax</div><div class="fax-detail">' . $fax . '</div></div>';
    }
    if (!empty($address['URL'])) {
      $html .=   '<div class="box"><div class="url-label">URL</div><div class="url-detail">' . '<a href="http://'. $address['URL'] . '" target="_blank">' . $address['URL'] . '</a></div></div>';
    }
    if (!empty($address['URLTwitter'])){
      $html .= '<div class="box"><div class="url-label">Twitter</div><div class="url-detail">'. '<a href="http://twitter.com/'. $address['URLTwitter'] .'" target="_blank">' . '@'.$address['URLTwitter'] . '</a></div></div>';
    }
    if (!empty($address['URLFB'])){
      $html .= '<div class="box"><div class="url-label">Facebook</div><div class="url-detail">'. '<a href="http://facebook.com/'.$address['URLFB'] . '" target="_blank">' . '@'.$address['URLFB'] . '</a></div></div>';
    }
    if (!empty($address['Email'])) {
      $html .=   '<div class="box"><div class="email-label">Email</div><div class="email-detail">' . $address['Email'] . '</div></div>';
    }
  }
  // End official-addresses
  $html .=     '</div>';

  // End official-body
  $html .=   '</div>';
  // End official-box
  $html .= '</div>';

  return $html;
}

/**
 * This creates the results html for the full doeo page.
 *
 * @param $data
 *
 * @return string
 */
function doeo_theme_doeo_results ($data) {
  $doeo_html = '';
  $full_html = '';
  $officials = $data['doeo'];
  foreach ($officials as $jurisdiction_type_id => $officials_group) {
    $jurisdiction_level = $officials_group[0]['JurisdictionLevel'];
    $jurisdiction_type = $officials_group[0]['JurisdictionType'];
    $doeo_html .= '<div class="jurisdiction-group">';
    $doeo_html .=   '<div class="jurisdiction-group-label">';
    $doeo_html .=     '<div class="jurisdiction-label">' . $jurisdiction_level . '</div>';
    $doeo_html .=     '<div class="jurisdiction-type">' . $jurisdiction_type . '</div>';
    $doeo_html .=   '</div>';
    $doeo_html .=   '<div class="officials">';
    foreach ($officials_group as $official) {
      $doeo_html .= theme('elected_official', ['elected_official' => $official]);
    }
    $doeo_html .=   '</div>';
    $doeo_html .= '</div>';
  }
  if (!empty($doeo_html)) {
    $full_html .= '<div id="doeo-wrappers" class="doeo-wrapper">' . $doeo_html;
    $full_html .= '<span class="print-doeo"><a id="print-doeo-button">Print Directory</a></span></div>';
  }

  return $full_html;
}

/**
 *  JurisdictionTypeId
 *
 * @param $data
 *
 * @return string
 */
function doeo_theme_doeo ($data) {
  $navigation_html = '';
  $doeo_html = '';
  $full_html = '';
  $last_jurisdiction_level = '';
  $officials = $data['doeo'];
  if (!empty($officials)) {
    foreach ($officials as $jurisdiction_type_id => $officials_group) {
      $jurisdiction_level = $officials_group[0]['JurisdictionLevel'];
      $jurisdiction_type = $officials_group[0]['JurisdictionType'];
      $doeo_html .= '<div class="jurisdiction-group">';
      $doeo_html .= '<a name="' . $jurisdiction_type_id . '"></a>';
      $doeo_html .= '<div class="jurisdiction-group-label">';
      $doeo_html .= '<div class="jurisdiction-label">' . $jurisdiction_level . '</div>';
      $doeo_html .= '<div class="jurisdiction-type">' . $jurisdiction_type . '</div>';
      $doeo_html .= '</div>';
      $doeo_html .= '<div class="officials">';
      foreach ($officials_group as $official) {
        $doeo_html .= theme('elected_official', ['elected_official' => $official]);
      }
      $doeo_html .= '</div>';
      $doeo_html .= '</div>';
      // Add the navigation for this section.
      // We have found a new section.
      if ($last_jurisdiction_level !== $jurisdiction_level) {
        // if this isn't the first section close the last one.
        if ($last_jurisdiction_level !== '') {
          $navigation_html .= '</div>';
        }
        // Start the group for the new section.
        $navigation_html .= '<div class="jurisdiction-nav-group"><div class="jurisdiction-nav-heading">' . $jurisdiction_level . '</div>';
        $last_jurisdiction_level = $jurisdiction_level;
      }
      // Add the anchor to the jurisdiction group.
      $navigation_html .= '<div class="jurisdiction-href"><a href="#' . $jurisdiction_type_id . '">' . $jurisdiction_type . '</a></div>';
    }
    // The last navigation element doesn't get closed inside the loop.
    $navigation_html .= '</div>';
    $full_html .= '<div id="doeo-wrappers" class="doeo-wrapper"><div class="doeo-nav">' . $navigation_html . '</div>' . $doeo_html; //needed to wrap the navigation area for the borders
    $full_html .= '<span class="print-doeo"><a id="print-doeo-button">Print Directory</a></span></div>';
  }

  return $full_html;
}
