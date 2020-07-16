#!/bin/bash
# Enable and disable modules in the settings files.
drush dis `cat modules_not_installed.txt`
drush pm-uninstall `cat modules_not_installed.txt`
drush dis `cat modules_disabled.txt`
drush en `cat modules_enabled.txt`