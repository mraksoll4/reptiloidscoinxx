// Copyright (c) 2016-2018 The ReptiloidsCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef REPTILOIDSCOIN_WALLET_TEST_WALLET_TEST_FIXTURE_H
#define REPTILOIDSCOIN_WALLET_TEST_WALLET_TEST_FIXTURE_H

#include <test/test_reptiloidscoin.h>

#include <interfaces/chain.h>
#include <interfaces/wallet.h>
#include <wallet/wallet.h>

#include <memory>

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    explicit WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();

    std::unique_ptr<interfaces::Chain> m_chain = interfaces::MakeChain();
    CWallet m_wallet;
};

#endif // REPTILOIDSCOIN_WALLET_TEST_WALLET_TEST_FIXTURE_H
