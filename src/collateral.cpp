// Copyright (c) 2020 The TradeTensor developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 500) {
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 7000) {
        nCollateralRequired = 5000 * COIN;
    } else if (nHeight <= 20000) {
        nCollateralRequired = 7000 * COIN;
    } else if (nHeight <= 40000) {
        nCollateralRequired = 10000 * COIN;
    } else if (nHeight <= 60000) {
        nCollateralRequired = 10000 * COIN;
    } else if (nHeight <= 75000) {
        nCollateralRequired = 10000 * COIN;
    } else if (nHeight <= 120000) {
        nCollateralRequired = 13000 * COIN;
    } else if (nHeight <= 150000) {
        nCollateralRequired = 13000 * COIN;
    } else if (nHeight <= 180000) {
        nCollateralRequired = 13000 * COIN;
    } else if (nHeight <= 200000) {
        nCollateralRequired = 13000 * COIN;
    } else if (nHeight <= 250000) {
        nCollateralRequired = 15000 * COIN;
    } else if (nHeight <= 4666120) {
        nCollateralRequired = 17000 * COIN;
    } else {
        nCollateralRequired = 18000.0001234 * COIN;
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
