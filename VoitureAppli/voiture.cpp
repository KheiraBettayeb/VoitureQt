#include "voiture.h"

Voiture::Voiture():mModele(""),mKilometrage(0),mJaugeCarburant(0)
{

}

Voiture::Voiture(QString modele, int kilometrage, int jaugecarburant):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugecarburant)
{

}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

void Voiture::rouler(int km)
{
    int conso = 0;

    if (mKilometrage <= 150000)
    {
        conso = (500/100) * km;
    }
    else
    {
        conso = (1000/100) * km;
    }

    if (mJaugeCarburant<conso ){
        throw std::invalid_argument ("Pas assez d'essence");

    }
    else
    {
        this->setKilometrage(mKilometrage+km);
        this->setJaugeCarburant(mJaugeCarburant-(conso));

    }

}
