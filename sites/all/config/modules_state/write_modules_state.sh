#!/bin/bash          
# Save the current state of the modules
drush pml --status=not\ installed --format=list --type=module | sort > modules_not_installed.txt
drush pml --status=disabled --format=list --type=module | sort > modules_disabled.txt
drush pml --status=enabled --format=list --type=module | sort > modules_enabled.txt
