#include <iostream>
#include <string>

// Клас, який представляє основний об'єкт (автомобіль)
class Car {
public:
    void setBrand(const std::string& brand) {
        brand_ = brand;
    }

    void setModel(const std::string& model) {
        model_ = model;
    }

    void setEngine(const std::string& engine) {
        engine_ = engine;
    }

    void setTransmission(const std::string& transmission) {
        transmission_ = transmission;
    }

    void showInfo() const {
        std::cout << "Car Info: " << brand_ << " " << model_ << ", Engine: " << engine_
                  << ", Transmission: " << transmission_ << std::endl;
    }

private:
    std::string brand_;
    std::string model_;
    std::string engine_;
    std::string transmission_;
};

// Абстрактний Будівельник
class CarBuilder {
public:
    virtual void buildBrand() = 0;
    virtual void buildModel() = 0;
    virtual void buildEngine() = 0;
    virtual void buildTransmission() = 0;
    virtual Car getResult() = 0;
};

// Конкретний Будівельник для спортивного автомобіля
class SportsCarBuilder : public CarBuilder {
public:
    void buildBrand() override {
        car_.setBrand("Ferrari");
    }

    void buildModel() override {
        car_.setModel("488 GTB");
    }

    void buildEngine() override {
        car_.setEngine("V8 Twin Turbo");
    }

    void buildTransmission() override {
        car_.setTransmission("7-speed Dual-Clutch");
    }

    Car getResult() override {
        return car_;
    }

private:
    Car car_;
};

// Директор, який використовує Будівельника для конструювання об'єкта
class CarDirector {
public:
    Car constructCar(CarBuilder& builder) {
        builder.buildBrand();
        builder.buildModel();
        builder.buildEngine();
        builder.buildTransmission();
        return builder.getResult();
    }
};

int main() {
    // Використання шаблону "Будівник"
    CarDirector director;
    SportsCarBuilder sportsCarBuilder;

    Car sportsCar = director.constructCar(sportsCarBuilder);
    sportsCar.showInfo();

    return 0;
}
