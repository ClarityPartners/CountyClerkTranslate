var gulp = require('gulp'),
    sass = require('gulp-sass'),
    notify = require('gulp-notify'),
    uglify = require('gulp-uglify'),
    minify = require('gulp-clean-css'),
    shell = require('gulp-shell'),
    exec = require('child_process').exec;
var $    = require('gulp-load-plugins')();


gulp.task('sass', function() {
  return gulp.src('scss/*.scss')
    .pipe(sass().on('error', sass.logError))
    .pipe(gulp.dest('css'))
    .pipe(notify({
      title: "SASS Compiled",
      message: "All SASS files have been recompiled to CSS.",
      onLast: true
    }));
});
gulp.task('compress', function() {
  return gulp.src('js/*.js')
    .pipe(uglify({
	compress:true,
	output: {beautify:false}
     }))
    //.pipe(rename({ suffix: '.min' }))
    .pipe(gulp.dest('js-min'))
    .pipe(notify({
      title: "JS Minified",
      message: "All JS files in the theme have been minified.",
      onLast: true
    }));
});

gulp.task('drush', function (cb) {
   exec('drush cc all', function(err, stdout, stderr){
   cb(err);
   });
})

gulp.task('minify-css',() => {
  return gulp.src('css/*.css')
    .pipe(minify())
    .pipe(gulp.dest('css'))
    .pipe(notify({
      title: "CSS Minified",
      message: "CSS file has been minified.",
      onLast: true
    }));
});

gulp.task('watch', function() {
  gulp.watch(['scss/**/*.scss'], ['sass']);
  gulp.watch('js/**/*.js', ['compress']);
  gulp.watch(['scss/**/*.scss'], ['drush']);
  gulp.watch('css/**/*.css', ['minify-css']);
});

gulp.task('default', ['watch']);
