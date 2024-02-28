# Temperature Converter Qt

---

### Introduction

This project started from a post I saw on Facebook. Some random user posted 
in a C++ group asking, probably for some homework he had to do, asking how 
to make a program in C++ to convert Fahrenheit to Celsius. I wrote the program
quickly, but decided it was the perfect example to practice with Qt and QML.

---

### Signals and Slots

One of the key things that we're doing in this project is using Signals and 
Slots. This is Qt's version of callback functions. Essentially, when something
happens that we want to track, or rather to activate some function later, we 
emit a signal. For example, when the convert button is pressed, we want to emit
a signal, to let the slots (callback function), defined somewhere else, know that 
we've clicked convert, and something needs to be done.

The key here is that we can emit signals from both Qml and C++. We can also handle 
the signals with Slots in Qml or C++. 

So in our C++ program, we define a TemperatureConverter class. It has functions 
like:
	
	convertTemperatureFromFahrenheitToCelsius
	convertTemperatureFromCelsiusToFahrenheit
	fahrenheitTemperature
	setFahrenheitTemperature

The functions that are explicitly defined as slots (see TemperatureConverter.hpp) 
will be accessible from the Qml file. In order to facilitate this, we will have 
to include the header for our class in the main.cpp file. It's also worth noting, 
for the moc (Qt's reflection tool) to generate the correct code for the Q_OBJECT
class declaration, we need to add the header to the CMakeLists.txt file. See the 
CMakeLists.txt file in the source folder for more...

So we add our header to the main.cpp file. We then can create an instance of our
class, and add it to the engine which processes the qml files, so it's available 
to them. Here's what that line looks like:

	engine.rootContext()->setContextProperty("temperatureConverter", new TemperatureConverter);

Now, in qml, when we reference temperatureConverter, we can access it's member 
functions, including the regular ones, not just the slots. 

---

### Connecting things in Qml

So normally, with Qt Widgets and such, we would use a connect() function call. 
With Qml, we do it something like this:

	Connections {
        	target: temperatureConverter
        	function onTemperatureConvertedFromFahrenheitToCelsius(celsiusTemperature) {
            	// Update the displayed Celsius temperature
            	resultText.text = "Result: " + celsiusTemperature.toFixed(2) + "°C"
        	}
    	}	

As you can see, we add the target temperatureConverter, which we described above. We then give the name
of the function, with the same name as our signals defined in our header, but with On before. We then can
use this as we need, as outlined above.


---






 

