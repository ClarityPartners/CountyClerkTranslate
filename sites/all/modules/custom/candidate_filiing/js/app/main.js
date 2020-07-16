function setObjectPropertyByName(o, a, b) { o[a] = b; return o; } // computed property names

function numeralAddCommas(intNum) {
	return (intNum + '').replace(/(\d)(?=(\d{3})+$)/g, '$1,');
}

﻿ko.bindingHandlers.sort = {
	init: function (element, valueAccessor, allBindingsAccessor, viewModel, bindingContext) {
		var asc = false;
		element.style.cursor = 'pointer';

		element.onclick = function () {
			var value = valueAccessor();
			var prop = value.prop;
			var data = value.arr;

			asc = !asc;

			data.sort(function (left, right) {
				var rec1 = left;
				var rec2 = right;

				if (!asc) {
					rec1 = right;
					rec2 = left;
				}

				var props = prop.split('.');
				for (var i in props) {
					var propName = props[i];
					var parenIndex = propName.indexOf('()');
					if (parenIndex > 0) {
						propName = propName.substring(0, parenIndex);
						rec1 = rec1[propName]();
						rec2 = rec2[propName]();
					} else {
						rec1 = rec1[propName];
						rec2 = rec2[propName];
					}
				}

				return rec1 == rec2 ? 0 : rec1 < rec2 ? -1 : 1;
			});
		};
	}
};

ko.bindingHandlers.fadeVisible = {
	init: function (element, valueAccessor) {
		// Initially set the element to be instantly visible/hidden depending on the value
		var value = valueAccessor();
		jQuery(element).toggle(ko.unwrap(value)); // Use "unwrapObservable" so we can handle values that may or may not be observable
	},
	update: function (element, valueAccessor) {
		// Whenever the value subsequently changes, slowly fade the element in or out
		var value = valueAccessor();
		ko.unwrap(value) ? jQuery(element).fadeIn(200) : jQuery(element).fadeOut(400);
	}
};

ko.bindingHandlers.largeNumber = {
        init: function(element, valueAccessor) {
                    var value = valueAccessor();
                    var interceptor = ko.computed({
                                    read: function() {
                                                        return numeralAddCommas(ko.unwrap(value));
                                                    },
                                    write: function(newValue) {
                                                        value(numeral().unformat(newValue));
                                                        value.valueHasMutated();
                                                    }
                                }).extend({notify: 'always'});
                    if (element.tagName.toLowerCase() !== 'input') {
                        ko.applyBindingsToNode(element, { text: interceptor });
                    }
                }
};

(function () {
	var D = new Date('2011-06-02T09:34:29+02:00');
	if (!D || +D !== 1307000069000) {
		Date.fromISO = function (s) {
			var day,
				tz,
				rx = /^(\d{4}\-\d\d\-\d\d([tT ][\d:\.]*)?)([zZ]|([+\-])(\d\d):(\d\d))?$/,
				p = rx.exec(s) || [];
			if (p[1]) {
				day = p[1].split(/\D/);
				for (var i = 0, L = day.length; i < L; i++) {
					day[i] = parseInt(day[i], 10) || 0;
				};
				day[1] -= 1;
				day = new Date(Date.UTC.apply(Date, day));
				if (!day.getDate()) return NaN;
				if (p[5]) {
					tz = (parseInt(p[5], 10) * 60);
					if (p[6]) tz += parseInt(p[6], 10);
					if (p[4] == '+') tz *= -1;
					if (tz) day.setUTCMinutes(day.getUTCMinutes() + tz);
				}
				return day;
			}
			return NaN;
		};
	} else {
		Date.fromISO = function (s) {
			return new Date(s);
		};
	}
})();

function DateTimeUtility(datetimeValue) {
	var value = Date.fromISO(datetimeValue);

	var defaultSeparator = ', ';

	return {
		asTimeSince: function () {
			var seconds = Math.floor((new Date() - value) / 1000);

			if (seconds <= 0) {
				return "0 seconds ago";
			}

			var interval = Math.floor(seconds / 86400);
			if (interval > 1) {
				return interval + " days ago";
			}
			interval = Math.floor(seconds / 3600);
			if (interval > 1) {
				return interval + " hours ago";
			}
			interval = Math.floor(seconds / 60);
			if (interval > 1) {
				return interval + " minutes ago";
			}

			return Math.floor(seconds) + " seconds ago";
		},
		asHourMinuteTimeTwentyFour: function () {
			var valueHours = value.getHours();
			var valueMinutes = value.getMinutes();

			valueHours = (valueHours < 10) ? '0' + valueHours : valueHours;
			valueMinutes = (valueMinutes < 10) ? '0' + valueMinutes : valueMinutes;

			return valueHours + ':' + valueMinutes;
		},
		asHourMinuteTime: function () {
			var valueHours = value.getHours();
			var valueMinutes = value.getMinutes();

			var valueAMorPM = "am";
			if (valueHours >= 12) {
				valueAMorPM = "pm";
			}
			if (valueHours > 12) {
				valueHours = valueHours - 12;
			}
			if (valueHours === 0) {
				valueHours = 12;
			}

			valueHours = (valueHours < 10) ? '0' + valueHours : valueHours;
			valueMinutes = (valueMinutes < 10) ? '0' + valueMinutes : valueMinutes;

			return valueHours + ':' + valueMinutes + " " + valueAMorPM;
		},
		asTime: function () {
			var valueHours = value.getHours();
			var valueMinutes = value.getMinutes();
			var valueSeconds = value.getSeconds();

			valueHours = (valueHours < 10) ? '0' + valueHours : valueHours;
			valueMinutes = (valueMinutes < 10) ? '0' + valueMinutes : valueMinutes;
			valueSeconds = (valueSeconds < 10) ? '0' + valueSeconds : valueSeconds;

			return valueHours + ':' + valueMinutes + ':' + valueSeconds;
		},
		asLocaleTime: function () {
			return value.toLocaleTimeString();
		},
		asDate: function () {
			var valueMonth = value.getMonth() + 1;
			var valueDay = value.getDate();
			var valueYear = value.getFullYear();

			var shortMonth = '01';
			if (valueMonth === 1) { shortMonth = '01'; }
			else if (valueMonth === 2) { shortMonth = '02'; }
			else if (valueMonth === 3) { shortMonth = '03'; }
			else if (valueMonth === 4) { shortMonth = '04'; }
			else if (valueMonth === 5) { shortMonth = '05'; }
			else if (valueMonth === 6) { shortMonth = '06'; }
			else if (valueMonth === 7) { shortMonth = '07'; }
			else if (valueMonth === 8) { shortMonth = '08'; }
			else if (valueMonth === 9) { shortMonth = '09'; }
			else if (valueMonth === 10) { shortMonth = '10'; }
			else if (valueMonth === 11) { shortMonth = '11'; }
			else if (valueMonth === 12) { shortMonth = '12'; }

			valueDay = (valueDay < 10) ? '0' + valueDay : valueDay;

			return valueYear + '/' + shortMonth + '/' + valueDay;
		},
		asFriendlyDate: function () {
			var valueMonth = value.getMonth() + 1;
			var valueDay = value.getDate();
			var valueYear = value.getFullYear();

			var shortMonth = '01';
			if (valueMonth === 1) { shortMonth = '01'; }
			else if (valueMonth === 2) { shortMonth = '02'; }
			else if (valueMonth === 3) { shortMonth = '03'; }
			else if (valueMonth === 4) { shortMonth = '04'; }
			else if (valueMonth === 5) { shortMonth = '05'; }
			else if (valueMonth === 6) { shortMonth = '06'; }
			else if (valueMonth === 7) { shortMonth = '07'; }
			else if (valueMonth === 8) { shortMonth = '08'; }
			else if (valueMonth === 9) { shortMonth = '09'; }
			else if (valueMonth === 10) { shortMonth = '10'; }
			else if (valueMonth === 11) { shortMonth = '11'; }
			else if (valueMonth === 12) { shortMonth = '12'; }

			valueDay = (valueDay < 10) ? '0' + valueDay : valueDay;

			return shortMonth + '/' + valueDay + '/' + valueYear;
		},
		asLocaleDate: function () {
			return value.toLocaleDateString();
		},
		asDateString: function () {
			return value.toDateString();
		},
		asDateTime: function (separatorDateTime) {
			if (!separatorDateTime) {
				separatorDateTime = defaultSeparator;
			}

			return this.asDate() + separatorDateTime + this.asTime();
		},
		asDateHourMinuteTime: function (separatorDateTime) {
			if (!separatorDateTime) {
				separatorDateTime = defaultSeparator;
			}

			return this.asDate() + separatorDateTime + this.asHourMinuteTime();
		}
	};
}

// JavaScript / HTML5 Shims (IE 8 compatibility) //

// HTML5 Shim: Array.reduce
// Production steps of ECMA-262, Edition 5, 15.4.4.21
// Reference: http://es5.github.io/#x15.4.4.21
if (!Array.prototype.reduce) {
	// ReSharper disable once NativeTypePrototypeExtending
	Array.prototype.reduce = function (callback /*, initialValue*/) {
		'use strict';
		if (this == null) {
			throw new TypeError('Array.prototype.reduce called on null or undefined');
		}
		if (typeof callback !== 'function') {
			throw new TypeError(callback + ' is not a function');
		}
		var t = Object(this), len = t.length >>> 0, k = 0, value;
		if (arguments.length == 2) {
			value = arguments[1];
		} else {
			while (k < len && !(k in t)) {
				k++;
			}
			if (k >= len) {
				throw new TypeError('Reduce of empty array with no initial value');
			}
			value = t[k++];
		}
		for (; k < len; k++) {
			if (k in t) {
				value = callback(value, t[k], k, t);
			}
		}
		return value;
	};
}

// HTML5 Shim: Array.indexOf
if (!Array.prototype.indexOf) {
	// ReSharper disable once NativeTypePrototypeExtending
	Array.prototype.indexOf = function (elt /*, from*/) {
		var len = this.length >>> 0;

		var from = Number(arguments[1]) || 0;
		from = (from < 0)
			? Math.ceil(from)
			: Math.floor(from);
		if (from < 0)
			from += len;

		for (; from < len; from++) {
			if (from in this &&
				this[from] === elt)
				return from;
		}
		return -1;
	};
}

// HTML5 Shim: String.trim
if (typeof String.prototype.trim !== 'function') {
	// ReSharper disable once NativeTypePrototypeExtending
	String.prototype.trim = function () {
		return this.replace(/^\s+|\s+$/g, '');
	}
}
