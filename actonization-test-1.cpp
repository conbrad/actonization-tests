#include <iostream>
#include <cstdint>
using namespace std;

const uint64_t MAX_CAPACITY = 1000;

int totalNationMeetings = 0;

enum quality {
	HIGH,
	MEDIUM,
	LOW
};

class Wood {
public:
	Wood();
	int amount;
	quality woodQuality;
	void setQuality(quality newQuality);
};

Wood::Wood() {
	amount = 0;
	woodQuality = LOW;
}

void Wood::setQuality(quality newQuality) {
	woodQuality = newQuality;
}

class Oil {
public:
	Oil();
	int amount;
	quality oilQuality;
	void setQuality(quality newQuality);
};

Oil::Oil() {
	amount = 0;
	oilQuality = LOW;
}

void Oil::setQuality(quality newQuality) {
	oilQuality = newQuality;
}

class Goods {
public:
	Goods();
	int amount;
	quality goodsQuality;
	void setQuality(quality newQuality);
};

Goods::Goods() {
	amount = 0;
	goodsQuality = LOW;
}

void Goods::setQuality(quality newQuality) {
	goodsQuality = newQuality;
}

class MapleSyrup {
public:
	MapleSyrup();
	int amount;
	quality syrupQuality;
	void setQuality(quality newQuality);
};

MapleSyrup::MapleSyrup() {
	amount = 0;
	syrupQuality = LOW;
}

void MapleSyrup::setQuality(quality newQuality) {
	syrupQuality = newQuality;
}

class Vanilla {
public:
	Vanilla();
	int amount;
	quality vanillaQuality;
	void setQuality(quality newQuality);
};

Vanilla::Vanilla() {
	amount = 0;
	vanillaQuality = HIGH;
}

void Vanilla::setQuality(quality newQuality) {
	vanillaQuality = newQuality;
}

class Tortillas {
public:
	Tortillas();
	int amount;
	quality tortillaQuality;
	void setQuality(quality newQuality);
};

Tortillas::Tortillas() {
	amount = 0;
	tortillaQuality = HIGH;
}

void Tortillas::setQuality(quality newQuality) {
	tortillaQuality = newQuality;
}

class Cars {
public:
	Cars();
	int amount;
	quality carQuality;
	void setQuality(quality newQuality);
};

Cars::Cars() {
	amount = 0;
	carQuality = MEDIUM;
}

void Cars::setQuality(quality newQuality) {
	carQuality = newQuality;
}

class US {
private:
	int nextWoodSilo;
	int nextOilBarrel;	
	int nextGoodsBox;
	
	Wood *woodSilos[MAX_CAPACITY];
	Oil *oilBarrels[MAX_CAPACITY];
	Goods *goodsBoxes[MAX_CAPACITY];

public:
	US();
	void logWood();
	void pumpOil();
	void bakeGoods();
	void exportWood(int amount);
	void exportOil(int amount);
	void exportGoods(int amount);
	bool atWoodCapacity();
	bool atOilCapacity();
	bool atGoodsCapacity();
};

US::US() {
	nextWoodSilo = 0;
	nextOilBarrel = 0;
	nextGoodsBox = 0;
}

void US::logWood() {
	if(nextWoodSilo == MAX_CAPACITY) {
		cout << "US wood silos are full" << endl;
		return;
	}	

	Wood *woodToFillSilo = new Wood();
	woodToFillSilo->woodQuality = MEDIUM;
	woodSilos[nextWoodSilo] = woodToFillSilo;
	nextWoodSilo++;
}

void US::pumpOil() {
	if(nextOilBarrel == MAX_CAPACITY) {
		cout << "US oil barrels are full" << endl;
		return;
	}	

	Oil *oilToFillBarrel = new Oil();
	oilToFillBarrel->oilQuality = MEDIUM;
	oilBarrels[nextOilBarrel] = oilToFillBarrel;
	nextOilBarrel++;
}

void US::bakeGoods() {
	if(nextGoodsBox == MAX_CAPACITY) {
		cout << "US goods boxes are full" << endl;
		return;
	}	

	Goods *goodsToFillBox = new Goods();
	goodsToFillBox->goodsQuality = LOW;
	goodsBoxes[nextGoodsBox] = goodsToFillBox;
	nextGoodsBox++;
}

void US::exportWood(int amount) {
	if(amount > nextWoodSilo) {
		cout << "Not enough wood!" << endl;
		return;
	}
	
	for(int i=nextWoodSilo; i > (nextWoodSilo - amount); i--) {
		delete woodSilos[i];
	}

	nextWoodSilo -= amount;
}


void US::exportOil(int amount) {
	if(amount > nextOilBarrel) {
		cout << "Not enough oil!" << endl;
		return;
	}
	
	for(int i=nextOilBarrel; i > (nextOilBarrel - amount); i--) {
		delete oilBarrels[i];
	}

	nextOilBarrel -= amount;
}


void US::exportGoods(int amount) {
	if(amount > nextGoodsBox) {
		cout << "Not enough goods!" << endl;
		return;
	}
	
	for(int i=nextGoodsBox; i > (nextGoodsBox - amount); i--) {
		delete goodsBoxes[i];
	}

	nextGoodsBox -= amount;
}

bool US::atWoodCapacity() {
	return nextWoodSilo == MAX_CAPACITY;
}

bool US::atOilCapacity() {
	return nextOilBarrel == MAX_CAPACITY;
}

bool US::atGoodsCapacity() {
	return nextGoodsBox == MAX_CAPACITY;
}

class Canada {
private:
	int nextWoodSilo;
	int nextOilBarrel;
	int nextSyrupBarrel;

	Wood *woodSilos[MAX_CAPACITY];
	Oil *oilBarrels[MAX_CAPACITY];
	MapleSyrup *syrupBarrels[MAX_CAPACITY];
public:
	Canada();
	void logWood();
	void pumpOil();
	void milkTrees();
	void exportWood(int amount);
	void exportOil(int amount);
	void exportSyrup(int amount);
	bool atWoodCapacity();
	bool atOilCapacity();
	bool atSyrupCapacity();
};

Canada::Canada() {
	nextWoodSilo = 0;
	nextOilBarrel = 0;
	nextSyrupBarrel = 0;
}

void Canada::logWood() {
	if(nextWoodSilo == MAX_CAPACITY) {
		cout << "Canadian wood silos are full" << endl;
		return;
	}

	Wood *woodToFillSilo = new Wood();
	woodToFillSilo->woodQuality = HIGH;
	woodSilos[nextWoodSilo] = woodToFillSilo;
	nextWoodSilo++;
}

void Canada::pumpOil() {
	if(nextOilBarrel == MAX_CAPACITY) {
		cout << "Canadian oil barrels are full" << endl;
		return;
	}
	Oil *oilToFillBarrel = new Oil();
	oilToFillBarrel->oilQuality = MEDIUM;
	oilBarrels[nextOilBarrel] = oilToFillBarrel;
	nextOilBarrel++;
}

void Canada::milkTrees() {
	if(nextSyrupBarrel == MAX_CAPACITY) {
		cout << "Canadian syrup barrels are full" << endl;
		return;
	}
	MapleSyrup *syrupToFillBarrel = new MapleSyrup();
	syrupToFillBarrel->syrupQuality = HIGH;
	syrupBarrels[nextSyrupBarrel] = syrupToFillBarrel;
	nextSyrupBarrel++;
}

void Canada::exportWood(int amount) {
	if(amount > nextWoodSilo) {
		cout << "Not enough wood!" << endl;
		return;
	}
	
	for(int i=nextWoodSilo; i > (nextWoodSilo - amount); i--) {
		delete woodSilos[i];
	}

	nextWoodSilo -= amount;
}


void Canada::exportOil(int amount) {
	if(amount > nextOilBarrel) {
		cout << "Not enough oil!" << endl;
		return;
	}
	
	for(int i=nextOilBarrel; i > (nextOilBarrel - amount); i--) {
		delete oilBarrels[i];
	}

	nextOilBarrel -= amount;
}


void Canada::exportSyrup(int amount) {
	if(amount > nextSyrupBarrel) {
		cout << "Not enough syrup!" << endl;
		return;
	}
	
	for(int i=nextSyrupBarrel; i > (nextSyrupBarrel - amount); i--) {
		delete syrupBarrels[i];
	}

	nextSyrupBarrel -= amount;
}

bool Canada::atWoodCapacity() {
	return nextWoodSilo == MAX_CAPACITY;
}

bool Canada::atOilCapacity() {
	return nextOilBarrel == MAX_CAPACITY;
}

bool Canada::atSyrupCapacity() {
	return nextSyrupBarrel == MAX_CAPACITY;
}

class Mexico {
private:
	int nextVanillaBarrel;
	int nextTortillaSilo;
	int nextCarPallet;

	Vanilla *vanillaBarrels[MAX_CAPACITY];
	Tortillas *tortillaSilos[MAX_CAPACITY];
	Cars *carPallets[MAX_CAPACITY];
public:
	Mexico();
	void produceVanilla();
	void bakeTortillas();
	void manufactureCars();
	void exportVanilla(int amount);
	void exportTortillas(int amount);
	void exportCars(int amount);
	bool atVanillaCapacity();
	bool atTortillaCapacity();
	bool atCarCapacity();
};

Mexico::Mexico() {
	nextVanillaBarrel = 0;
	nextTortillaSilo = 0;
	nextCarPallet = 0;
}

void Mexico::produceVanilla() {
	if(nextVanillaBarrel == MAX_CAPACITY) {
		cout << "Mexican vanilla barrels are full" << endl;
		return;
	}
	Vanilla *vanillaToFillBarrel = new Vanilla();
	vanillaToFillBarrel->vanillaQuality = HIGH;
	vanillaBarrels[nextVanillaBarrel] = vanillaToFillBarrel;
	nextVanillaBarrel++;
}

void Mexico::bakeTortillas() {
	if(nextTortillaSilo == MAX_CAPACITY) {
		cout << "Mexican tortilla silos are full" << endl;
		return;
	}
	Tortillas *tortillasToFillSilo = new Tortillas();
	tortillasToFillSilo->tortillaQuality = HIGH;
	tortillaSilos[nextTortillaSilo] = tortillasToFillSilo;
	nextTortillaSilo++;
}

void Mexico::manufactureCars() {
	if(nextCarPallet == MAX_CAPACITY) {
		cout << "Mexican car pallets are full" << endl;
		return;
	}
	Cars *carsToFillPallet = new Cars();
	carsToFillPallet->carQuality = MEDIUM;
	carPallets[nextCarPallet] = carsToFillPallet;
	nextCarPallet++;
}

void Mexico::exportVanilla(int amount) {
	if(amount > nextVanillaBarrel) {
		cout << "Not enough vanilla!" << endl;
		return;
	}
	
	for(int i=nextVanillaBarrel; i > (nextVanillaBarrel - amount); i--) {
		delete vanillaBarrels[i];
	}

	nextVanillaBarrel = nextVanillaBarrel - amount;
}


void Mexico::exportTortillas(int amount) {
	if(amount > nextTortillaSilo) {
		cout << "Not enough tortillas!" << endl;
		return;
	}
	
	for(int i=nextTortillaSilo; i > (nextTortillaSilo - amount); i--) {
		delete tortillaSilos[i];
	}

	nextTortillaSilo = nextTortillaSilo - amount;
}


void Mexico::exportCars(int amount) {
	if(amount > nextCarPallet) {
		cout << "Not enough cars!" << endl;
		return;
	}
	
	for(int i=nextCarPallet; i > (nextCarPallet - amount); i--) {
		delete carPallets[i];
	}

	nextCarPallet = nextCarPallet - amount;
}

bool Mexico::atVanillaCapacity() {
	return nextVanillaBarrel == MAX_CAPACITY;
}

bool Mexico::atTortillaCapacity() {
	return nextTortillaSilo == MAX_CAPACITY;
}

bool Mexico::atCarCapacity() {
	return nextCarPallet == MAX_CAPACITY;
}
// Main helpers


int main() {
	US *instanceOfUS = new US();
	Canada *instanceOfCanada = new Canada();
	Mexico *instanceOfMexico = new Mexico();
	
	// Manufacture everything until capacity in the US
	cout << "Manufacturing in the US..." << endl;
	while(!instanceOfUS->atWoodCapacity()) {
		instanceOfUS->logWood();
	}

	while(!instanceOfUS->atOilCapacity()) {
		instanceOfUS->pumpOil();
	}

	while(!instanceOfUS->atGoodsCapacity()) {
		instanceOfUS->bakeGoods();
	}

	// Manufacture everything until capacity in Canada
	cout << "Manufacturing in Canada..." << endl;
	while(!instanceOfCanada->atWoodCapacity()) {
		instanceOfCanada->logWood();
	}

	while(!instanceOfCanada->atOilCapacity()) {
		instanceOfCanada->pumpOil();
	}

	while(!instanceOfCanada->atSyrupCapacity()) {
		instanceOfCanada->milkTrees();
	}

	// Manufacture everything until capacity in Mexico
	cout << "Manufacturing in Mexico..." << endl;
	while(!instanceOfMexico->atVanillaCapacity()) {
		instanceOfMexico->produceVanilla();
	}

	while(!instanceOfMexico->atTortillaCapacity()) {
		instanceOfMexico->bakeTortillas();
	}

	while(!instanceOfMexico->atCarCapacity()) {
		instanceOfMexico->manufactureCars();
	}
	
	
	// Access objects in arrays within different classes
	// in an attempt to cause cache thrashing
	
	cout << "Starting exports!" << endl;

	instanceOfCanada->exportWood(10);
	instanceOfUS->exportOil(200);
	instanceOfCanada->exportSyrup(646);

	// access global variable
	totalNationMeetings++;

	instanceOfMexico->exportVanilla(4353);

	// access global variable
	totalNationMeetings++;

	instanceOfCanada->exportOil(353);
	instanceOfUS->exportGoods(10000);	

	instanceOfMexico->exportCars(89543);
	instanceOfCanada->exportSyrup(3433);

	// access global variable
	totalNationMeetings++;

	delete instanceOfUS;
	delete instanceOfCanada;
	delete instanceOfMexico;
	return 0;
}
