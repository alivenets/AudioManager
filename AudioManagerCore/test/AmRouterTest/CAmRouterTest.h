/**
 * SPDX license identifier: MPL-2.0
 *
 * Copyright (C) 2012, BMW AG
 *
 * This file is part of GENIVI Project AudioManager.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *
* \author Aleksandar Donchev, aleksander.donchev@partner.bmw.de BMW 2013
 *
 * For further information see http://www.genivi.org/.
 *
 */

#ifndef DATABASETEST_H_
#define DATABASETEST_H_

#define UNIT_TEST 1

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include "CAmDatabaseHandlerMap.h"
#include "CAmControlReceiver.h"
#include "CAmControlSender.h"
#include "CAmRoutingSender.h"
#include "CAmRouter.h"
#include "CAmSocketHandler.h"
#include "../IAmControlBackdoor.h"
#include "../IAmCommandBackdoor.h"
#include "../CAmCommonFunctions.h"
#include "../MockIAmControlSend.h"
#include "../MockIAmCommandSend.h"


namespace am
{

class CAmRouterTest: public ::testing::Test
{
public:
    CAmRouterTest();
    ~CAmRouterTest();
    std::vector<std::string> plistRoutingPluginDirs;
    std::vector<std::string> plistCommandPluginDirs;
    CAmSocketHandler pSocketHandler;
    CAmControlSender pControlSender;
    CAmDatabaseHandlerMap pDatabaseHandler;
    CAmRouter pRouter;
    CAmRoutingSender pRoutingSender;
    CAmCommandSender pCommandSender;
    MockIAmCommandSend pMockInterface;
    MockIAmControlSend pMockControlInterface;
    IAmRoutingBackdoor pRoutingInterfaceBackdoor;
    IAmCommandBackdoor pCommandInterfaceBackdoor;
    IAmControlBackdoor pControlInterfaceBackdoor;
    CAmControlReceiver pControlReceiver;
    CAmCommonFunctions pCF;
    void SetUp();
    void TearDown();

    void createMainConnectionSetup();
};

}

#endif /* DATABASETEST_H_ */
