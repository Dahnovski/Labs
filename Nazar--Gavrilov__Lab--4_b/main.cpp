#include <iostream>
#include <string>

class Motor {
private:
    std::string manufacturer;
    std::string type;
    int power;

public:
    Motor(const std::string& man, const std::string& t, int p) : manufacturer(man), type(t), power(p) {}

    void setManufacturer(const std::string& man) {
        manufacturer = man;
    }

    void setType(const std::string& t) {
        type = t;
    }

    void setPower(int p) {
        power = p;
    }

    const std::string& getManufacturer() const {
        return manufacturer;
    }

    const std::string& getType() const {
        return type;
    }

    int getPower() const {
        return power;
    }
};

class Ship {
private:
    Motor* engine;
    int capacity;
    int waterMeter;
    std::string name;
    std::string port;

public:
    Ship(const std::string& shipName, const std::string& portName) : capacity(0), waterMeter(0), name(shipName), port(portName), engine(nullptr) {}

    ~Ship() {
        delete engine;
    }

    void setEngine(const Motor& motor) {
        delete engine;
        engine = new Motor(motor);
    }

    void setCapacity(int c) {
        capacity = c;
    }

    void setWaterMeter(int w) {
        waterMeter = w;
    }

    const std::string& getName() const {
        return name;
    }

    const std::string& getPort() const {
        return port;
    }

    int getCapacity() const {
        return capacity;
    }

    int getWaterMeter() const {
        return waterMeter;
    }

    const Motor* getEngine() const {
        return engine;
    }

    // Дополнительные настройки и действия для корабля
    void performCustomShipAction() const {
        std::cout << "Performing custom action for ship: " << name << std::endl;
    }
};

class PassengerSteamship : public Ship {
private:
    std::string additionalSetting;

public:
    PassengerSteamship(const std::string& shipName, const std::string& portName, const std::string& additionalSetting)
        : Ship(shipName, portName), additionalSetting(additionalSetting) {
        // Дополнительные настройки для парохода для пассажиров
    }

    // Дополнительные настройки и действия для парохода для пассажиров
    void setAdditionalSetting(const std::string& setting) {
        additionalSetting = setting;
    }

    void performCustomPassengerSteamshipAction() const {
        std::cout << "Performing custom action for passenger steamship: " << getName() << std::endl;
    }
};

int
main() {
    Motor motor("GMC", "TypeX", 2000);

    Ship ship("RENOVATIO", "PortA");
    ship.setEngine(motor);
    ship.setCapacity(1000);
    ship.setWaterMeter(50);
    ship.performCustomShipAction();

    PassengerSteamship passengerShip("PassengerShip", "PortB", "AdditionalSetting");
    passengerShip.setEngine(motor);
    passengerShip.setCapacity(500);
    passengerShip.setWaterMeter(30);
    passengerShip.setAdditionalSetting("NewAdditionalSetting");
    passengerShip.performCustomPassengerSteamshipAction();

    return 0;
}