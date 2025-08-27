// =====================================================================================
// Wallet.h
// =====================================================================================

// -----------------------------------
// defines

#pragma once

// -----------------------------------
// types

struct wallet
{
    unsigned long long m_euros;
    unsigned int       m_cents;
};

typedef struct wallet Wallet;

// -----------------------------------
// function prototypes

void                initWallet        (      Wallet* wallet, unsigned long long euros, unsigned int cents);
unsigned long long  getEuros          (const Wallet* wallet);
unsigned int        getCent           (const Wallet* wallet);
void                addWallet         (      Wallet* wallet, Wallet* other);
void                addEuros          (      Wallet* wallet, unsigned long long euros);
void                addEurosAndCents  (      Wallet* wallet, unsigned long long euros, unsigned int cents);
int                 subWallet         (      Wallet* wallet, Wallet* other);
int                 subEuros          (      Wallet* wallet, unsigned long long euros);
int                 subEurosAndCents  (      Wallet* wallet, unsigned long long euros, unsigned int cents);
int                 lessThan          (const Wallet* wallet, const Wallet* other);
int                 equals            (const Wallet* wallet, const Wallet* other);
unsigned long long  toCents           (const Wallet* wallet);
void                print             (const Wallet* wallet);

// =====================================================================================
// End-of-File
// =====================================================================================
    