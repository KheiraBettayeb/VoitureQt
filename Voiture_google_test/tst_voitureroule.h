#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"voiture.h"
#include<QDebug>

using namespace testing;

//on apelle les codes que l'ont mutualiser pareil,on joue sur la visibilité protected
class test01VoitureRoule: public Test{
protected:
    Voiture oldCar;
    int jaugeStart;
    int kmStart;

    //override je redefini une mecanisme qui existe deja
    void SetUp() override{
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Ford Mustang 1967");
    }

    //nettoyage si allocation dynamique faire des deletes
    void TearDown() override {
    qDebug() << "Do some cleaning";
}
};

TEST_F(test01VoitureRoule, ok)
{
    /*int kmStart = 160000;
    int jaugeStart = 1500;*/
   // Voiture voiture("Ferrari F40",kmStart,jaugeStart );
    int distance = 100;
    oldCar.rouler(distance);
    EXPECT_EQ(oldCar.kilometrage(), kmStart + distance)
            << "Kil;ometrage incorrect";
    // vieille voiture 10l/100km on divise par 10 et on multiple par 1000(car cl) dc c comme multiplier par 10
    EXPECT_EQ(oldCar.jaugeCarburant(), jaugeStart - distance * 10)
            << "Jauge Carburant incorrecte";
   // ASSERT_THAT(0, Eq(0));

}
//pour lui indiquer quelle valeurs sont a injecter
class testVoiturerecentRoule: public TestWithParam<int>{

};

TEST_P(testVoiturerecentRoule, Range)
{
   int kmStart = GetParam();
    int jaugeStart = 500;
    Voiture voiture("Ferrari F40",kmStart,jaugeStart );
    int distance = 100;
    //when
    voiture.rouler(distance);
    // exemple avec un matcher Eq(kmStart + distance)
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance))
            << "Kil;ometrage incorrect";
    // vieille voiture 10l/100km on divise par 10 et on multiple par 1000(car cl) dc c comme multiplier par 10
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance * 5))
            << "Jauge Carburant incorrecte";

}

//param(label qui rassemble le test, nomdutest/classe,valeurs qu'on fourni permet de declencher le test avec autant de valeurs qu'on veut
INSTANTIATE_TEST_SUITE_P(GroupVoitureRecnte,testVoiturerecentRoule,
                         Values(0, 10000, 50000, 149999));
                         //boucle va de 0 a 150000 pour tt les 10000 le 0 est inclut dans le test mais pas 150000 il n'est pas tester
                        // Range(0,150000,10000));

TEST_F(test01VoitureRoule, NoGaz)
{
   /* QString modele = "Renault Scenic";
    int kilometrage = 192000;
    int jaugeCarburant = 300;*/
   // Voiture voiture("Ferrari F40",kmStart, jaugeStart);
    int distance = 200;
    EXPECT_THROW(oldCar.rouler(200),std::invalid_argument);
   // EXPECT_EQ(oldCar.kilometrage(),192000);
    //EXPECT_EQ(oldCar.jaugeCarburant(),300);
    EXPECT_THAT(oldCar.kilometrage(),Eq(kmStart));
    EXPECT_THAT(oldCar.jaugeCarburant(),Eq(jaugeStart));
}

