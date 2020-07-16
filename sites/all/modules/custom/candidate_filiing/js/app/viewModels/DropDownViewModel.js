var DropDownViewModel = function DropDownViewModel(options, optionsValue, optionsText) {
	this.options = ko.observableArray(options);
	this.text = optionsText;
	this.value = optionsValue;
};