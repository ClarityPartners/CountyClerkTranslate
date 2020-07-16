<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<?php
    $social_menu = module_invoke('menu', 'block_view', 'menu-social-menu');
    $search = module_invoke('clarity_search', 'block_view', 'clarity_search');
    $google = module_invoke('gtranslate', 'block_view', 'gtranslate');

  if ($node = menu_get_object()) {
		  // Get the nid
		  $nid = $node->nid;
		  $node_title = $node->title;
		  $aliased_path=drupal_get_path_alias("node/".$nid);
		  //$segments = explode('/', $aliased_path);
		  $path = drupal_get_path_alias($_GET['q']);
		  $fs_refer = explode("/", $path);
		}
  global $user;
?>
<nav class="main-nav">
    <?php echo render($main_menu); ?>
    <div class="social-pane main-nav"><?php echo render($social_menu['content']); ?></div>
</nav>
<div class="canvas <?php echo $page_body; ?>">
<header id="navbar" role="banner" class="navbar container-fluid navbar-default <?php //print $navbar_classes; ?>">
  <div class="container-fluid"><?php //print $container_class; ?>
    <div class="navbar-header">
        <div class="hamburger-nav">
          <button class="hamburger hamburger--squeeze hide-for-medium" type="button"
                    aria-label="Menu" aria-controls="navigation">
              <span class="hamburger-box">
                <span class="hamburger-inner"></span>
              </span>
              <span class="menu-text"><?php echo t('Menu'); ?></span>
            </button>
        </div>

        <?php if ($logo): ?>
        <a class="logo navbar-btn col-sm-2 text-center desktop" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

        <div class="site-info">

            <?php if (!empty($site_slogan)): ?>
              <p class="lead navbar-brand"><?php print $site_slogan; ?></p>
            <?php endif; ?>

          <?php if (!empty($site_name)): ?>
            <a class="name navbar-slogan" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>

          <?php endif; ?>
        </div>

        <?php echo render($search['content']); ?>
        <div class="gtranslate-div"><?php echo t('Google Translate ').render($google['content']); ?></div>
        <div class="social-pane navi">
          <?php echo render($social_menu['content']); ?>
        </div>

    </div>

  </div>
</header>
  <div role="banner" id="page-header">
        <?php print render($page['header']); ?>
</div> <!-- /#page-header -->
<?php //solution that doesnt cause notice undefined issue

if($node && isset($node->field_landing_page)){
$items = field_get_items('node', $node, 'field_landing_page');
  if($items[0]['value'] == '1'){
    $title = '';
  }
}
?>

<div class="main-container <?php print $container_fixed ?>" id="no-padding">

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section <?php if (!empty($content_column_class)):
                       print $content_column_class;
             endif; ?> id="no-padding">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header <?php if(!empty($class_name)){ echo $class_name; } ?>"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>
    <?php if (!empty($page['sidebar_second']) && empty($landing)): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<?php if (!empty($page['upper_footer'])): ?>
  <div class="upper-footer">
  <?php echo render($page['upper_footer']); ?>
</div>
<?php endif; ?>
<div class="clear-footer"></div>
<?php if (!empty($page['footer'])): ?>
  <footer class="footer container-fluid <?php //print $container_class; ?>">
      <div class="scrollTop"><span class="fa fa-chevron-up" aria-hidden="true"></span></div>
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>
<?php if (drupal_is_front_page()) {
    //block here
} ?>
</div>