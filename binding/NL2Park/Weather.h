#ifndef BINDING_NL2PARK_WEATHER_H
#define BINDING_NL2PARK_WEATHER_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Info/Weather.h>

namespace Binding {
    namespace NL2Park {
        class Weather : public Nan::ObjectWrap {
        public:
            explicit Weather(Library::NL2Park::Weather *weather) : _weather(weather) {}
            explicit Weather() : _weather(new Library::NL2Park::Weather) {}
            ~Weather() {}

            Library::NL2Park::Weather *getWeather() { return _weather; }

            static BINDING_MODULE_INIT("Weather",
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RainIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SnowIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(FogIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(WindIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(OvercastIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CloudsIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ThunderIntensity);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(OverwriteDefaultWeather);
               BINDING_PROTOTYPE_STATIC_METHOD(convertWindIntensity);
               BINDING_PROTOTYPE_STATIC_METHOD(convertFogIntensity);
             );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Weather);

            BINDING_METHOD_SETTER_GETTER_FLOAT(RainIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(SnowIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(FogIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(WindIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(OvercastIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(CloudsIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_FLOAT(ThunderIntensity, Weather);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(OverwriteDefaultWeather, Weather);

            static NAN_METHOD(convertWindIntensity) {
                if(!info[0]->IsNumber())
                    return Nan::ThrowTypeError("argument 1 must be of type Number");
                if(!info[1]->IsBoolean())
                    return Nan::ThrowTypeError("argument 2 must be of type Boolean");

                float result = Library::NL2Park::Weather::convertWindIntensity(
                    (float)Nan::To<double>(info[0]).FromJust(),
                    Nan::To<bool>(info[1]).FromJust()
                );

                info.GetReturnValue().Set(result);
            }

            static NAN_METHOD(convertFogIntensity) {
                if(!info[0]->IsNumber())
                    return Nan::ThrowTypeError("argument 1 must be of type Number");
                if(!info[1]->IsBoolean())
                    return Nan::ThrowTypeError("argument 2 must be of type Boolean");

                float result = Library::NL2Park::Weather::convertFogIntensity(
                    (float)Nan::To<double>(info[0]).FromJust(),
                    Nan::To<bool>(info[1]).FromJust()
                );

                info.GetReturnValue().Set(result);
            }

            Library::NL2Park::Weather *_weather;
        };
    }
}

#endif // BINDING_NL2PARK_WEATHER_H
