//
// Created by John on 2/28/2024.
//

#ifndef TEMPERATURECONVERTER_QT_TEMPERATURECONVERTER_HPP
#define TEMPERATURECONVERTER_QT_TEMPERATURECONVERTER_HPP

#include <QObject>

class TemperatureConverter : public QObject
{
Q_OBJECT
    Q_PROPERTY(double fahrenheitTemperature READ fahrenheitTemperature WRITE setFahrenheitTemperature NOTIFY fahrenheitTemperatureChanged)
    Q_PROPERTY(double celsiusTemperature READ celsiusTemperature WRITE setCelsiusTemperature NOTIFY celsiusTemperatureChanged)
    Q_PROPERTY(double kelvinTemperature READ kelvinTemperature WRITE setKelvinTemperature NOTIFY kelvinTemperatureChanged)


public:
    explicit TemperatureConverter(QObject *parent = nullptr);

    double fahrenheitTemperature() const;
    void setFahrenheitTemperature(double value);

    double celsiusTemperature() const;
    void setCelsiusTemperature(double value);

    double kelvinTemperature() const;
    void setKelvinTemperature(double value);

signals:
    void temperatureConvertedFromFahrenheitToCelsius(double celsiusTemperature);
    void temperatureConvertedFromCelsiusToFahrenheit(double fahrenheitTemperature);
    void temperatureConvertedFromFahrenheitToKelvin(double kelvinTemperature);
    void temperatureConvertedFromCelsiusToKelvin(double kelvinTemperature);
    void temperatureConvertedFromKelvinToFahrenheit(double fahrenheitTemperature);
    void temperatureConvertedFromKelvinToCelsius(double celsiusTemperature);
    void fahrenheitTemperatureChanged();
    void celsiusTemperatureChanged();
    void kelvinTemperatureChanged();

public slots:
    void convertTemperatureFromFahrenheitToCelsius(const QString &fahrenheitTemperature);
    void convertTemperatureFromCelsiusToFahrenheit(const QString &celsiusTemperature);
    void convertTemperatureFromFahrenheitToKelvin(const QString &fahrenheitTemperature);
    void convertTemperatureFromCelsiusToKelvin(const QString &celsiusTemperature);
    void convertTemperatureFromKelvinToFahrenheit(const QString &fahrenheitTemperature);
    void convertTemperatureFromKelvinToCelsius(const QString &celsiusTemperature);

private:
    double fahrenheitTemperature_;
    double celsiusTemperature_;
    double kelvinTemperature_;
};

#endif //TEMPERATURECONVERTER_QT_TEMPERATURECONVERTER_HPP
