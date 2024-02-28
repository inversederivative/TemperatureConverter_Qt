//
// Created by John on 2/28/2024.
//
#include <TemperatureConverter.hpp>
#include <QDebug>

TemperatureConverter::TemperatureConverter(QObject *parent) : QObject(parent),
                                                              fahrenheitTemperature_(0),
                                                              celsiusTemperature_(0),
                                                              kelvinTemperature_(0)
{
}

double TemperatureConverter::fahrenheitTemperature() const {
    return fahrenheitTemperature_;
}

void TemperatureConverter::setFahrenheitTemperature(double value)  {
    fahrenheitTemperature_ = value;
    emit fahrenheitTemperatureChanged();
}

double TemperatureConverter::celsiusTemperature() const {
    return celsiusTemperature_;
}

void TemperatureConverter::setCelsiusTemperature(double value)  {
    celsiusTemperature_ = value;
    emit celsiusTemperatureChanged();
}

double TemperatureConverter::kelvinTemperature() const {
    return kelvinTemperature_;
}

void TemperatureConverter::setKelvinTemperature(double value) {
    kelvinTemperature_ = value;
    emit kelvinTemperatureChanged();
}

void TemperatureConverter::convertTemperatureFromFahrenheitToCelsius(const QString &fahrenheitTemperature)
{
    bool ok;
    double fahrenheit = fahrenheitTemperature.toDouble(&ok);
    if (ok) {
        fahrenheitTemperature_ = fahrenheit;
        qDebug() << "convertTemperature called with: " << fahrenheitTemperature_;
        double celsius = (fahrenheit - 32) * 5 / 9;
        celsiusTemperature_ = celsius;
        emit temperatureConvertedFromFahrenheitToCelsius(celsius);
    }
}

void TemperatureConverter::convertTemperatureFromCelsiusToFahrenheit(const QString &celsiusTemperature)
{
    bool ok;
    double celsius = celsiusTemperature.toDouble(&ok);
    if (ok) {
        celsiusTemperature_ = celsius;
        double fahrenheit = (celsius * 9/5) + 32;
        fahrenheitTemperature_ = fahrenheit;
        emit temperatureConvertedFromCelsiusToFahrenheit(fahrenheit);
    }
}

void TemperatureConverter::convertTemperatureFromFahrenheitToKelvin(const QString &fahrenheitTemperature)
{
    bool ok;
    double fahrenheit = fahrenheitTemperature.toDouble(&ok);
    if (ok) {
        fahrenheitTemperature_ = fahrenheit;
        double kelvin = ((fahrenheit - 32) * 5 / 9) + 273.15;
        kelvinTemperature_ = kelvin;
        emit temperatureConvertedFromFahrenheitToKelvin(kelvin);
    }
}

void TemperatureConverter::convertTemperatureFromCelsiusToKelvin(const QString &celsiusTemperature)
{
    bool ok;
    double celsius = celsiusTemperature.toDouble(&ok);
    if (ok) {
        fahrenheitTemperature_ = celsius;
        double kelvin = celsius + 273.15;
        kelvinTemperature_ = kelvin;
        emit temperatureConvertedFromCelsiusToKelvin(kelvin);
    }
}

void TemperatureConverter::convertTemperatureFromKelvinToFahrenheit(const QString &kelvinTemperature)
{
    bool ok;
    double kelvin = kelvinTemperature.toDouble(&ok);
    if (ok) {
        kelvinTemperature_ = kelvin;
        // °F = (K − 273.15) × 1.8 + 32
        double fahrenheit = ((kelvin - 273.15) * 9/5) + 32;
        fahrenheitTemperature_ = fahrenheit;
        emit temperatureConvertedFromKelvinToFahrenheit(fahrenheit);
    }
}

void TemperatureConverter::convertTemperatureFromKelvinToCelsius(const QString &kelvinTemperature)
{
    bool ok;
    double kelvin = kelvinTemperature.toDouble(&ok);
    if (ok) {
        kelvinTemperature_ = kelvin;
        // °F = (K − 273.15) × 1.8 + 32
        double celsius = (kelvin - 273.15);
        celsiusTemperature_ = celsius;
        emit temperatureConvertedFromKelvinToCelsius(celsius);
    }
}
