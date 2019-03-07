#pragma once

#include <gtest/gtest.h>
//dans matchers presence de macro pour faire des test complexes
#include <gmock/gmock-matchers.h>
#include"voiture.h"

using namespace testing;

//peut avoir autant de test qu'on veut tant que le label est different(defaults)
TEST(testVoitureConstructor, Default)
{
    // 2 niveaux de verif EXPECT et ASSERT
    //si assertion pas verifier ca arrete le test
    //except qqsoit le scénario il continue il logeras les erreurs

    Voiture voiture;
    EXPECT_EQ(voiture.modele(), "");
    EXPECT_EQ(voiture.kilometrage(), 0);
    EXPECT_EQ(voiture.jaugeCarburant(), 0);


   // ASSERT_THAT(0, Eq(0));
}
TEST(testVoitureConstructor, Complet)
{
    QString modele = "Ferrari F40";
    int km = 20000;
    int jauge = 5000;
    Voiture voiture(modele,km,jauge);
    //si utilisation string on doit ecrire EXPECT_STREQ mais pour qstring pas besoin
    EXPECT_EQ(voiture.modele(), modele);
    EXPECT_EQ(voiture.kilometrage(), km);
    EXPECT_EQ(voiture.jaugeCarburant(), jauge);
    //si utilisation de double EXPECT_DOUBLE_EQ
}
