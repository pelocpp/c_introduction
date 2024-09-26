// =====================================================================================
// Wallet.c
// =====================================================================================

#include <stdio.h>

#include "Wallet.h"

// =====================================================================================
// Implementation

static void initWallet(Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    if (cents >= 100) {
        printf("Cents larger than 100 are not allowed!\n");
        wallet->m_cents = 0;
    }
    else {
        wallet->m_cents = cents;
    }

    wallet->m_euros = euros;
}

static unsigned long long getEuros(Wallet* wallet)
{
    return wallet->m_euros;
}

static unsigned int getCent(Wallet* wallet)
{
    return wallet->m_cents;
}

static void addWallet(Wallet* wallet, Wallet* other)
{
    wallet->m_cents = wallet->m_cents + other->m_cents;
    unsigned int carry = wallet->m_cents / 100;
    wallet->m_cents = wallet->m_cents % 100;
    wallet->m_euros = wallet->m_euros + other->m_euros + carry;
}

static void addEuros(Wallet* wallet, unsigned long long euros)
{
    wallet->m_euros = wallet->m_euros + euros;
}

static void addEurosAndCents(Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    Wallet tmp = { euros, cents };

    addWallet(wallet, &tmp);
}

static int subWallet(Wallet* wallet, Wallet* other)
{
    if (lessThan(wallet, other)) {
        printf("Not enough money available in wallet!\n");
        return 0;
    }

    // underrun
    if (wallet->m_cents < other->m_cents)
    {
        wallet->m_euros = wallet->m_euros - 1;
        wallet->m_cents = wallet->m_cents + 100;
    }

    wallet->m_euros = wallet->m_euros - other->m_euros;
    wallet->m_cents = wallet->m_cents - other->m_cents;

    return 1;
}

static int subEuros(Wallet* wallet, unsigned long long euros)
{
    if (wallet->m_euros < euros) {
        printf("Not enough money available in wallet!\n");
        return 0;
    }

    wallet->m_euros = wallet->m_euros - euros;

    return 1;
}

static int subEurosAndCents(Wallet* wallet, unsigned long long euros, unsigned int cents)
{
    Wallet tmp = { euros, cents };

    return subWallet(wallet, &tmp);
}

static int lessThan(Wallet* wallet, Wallet* other)
{
    if (wallet->m_euros < other->m_euros) {
        return 1;
    }
    else if (wallet->m_euros == other->m_euros && wallet->m_cents < other->m_cents) {
        return 1;
    }
    else {
        return 0;
    }
}

static int equals(Wallet* wallet, Wallet* other)
{
    if (wallet->m_euros == other->m_euros && wallet->m_cents == other->m_cents) {
        return 1;
    }
    else {
        return 0;
    }
}

static unsigned long long toCents(Wallet* wallet)
{
    return 100 * wallet->m_euros + wallet->m_cents;
}

static void print(Wallet* wallet)
{
    printf("%llu,%02u Euro\n", wallet->m_euros, wallet->m_cents);
}

static void exercise_wallet_01()
{
    Wallet wallet = { 0, 0 };

    print(&wallet);

    addEurosAndCents(&wallet, 10, 50);
    print(&wallet);

    subEurosAndCents(&wallet, 5, 75);
    print(&wallet);

    unsigned long long cents = toCents(&wallet);
    printf("Cents: %llu\n", cents);
}

static void exercise_wallet_02()
{
    Wallet wallet1 = { 3, 30 };
    Wallet wallet2 = { 3, 30 };

    print(&wallet1);
    print(&wallet2);

    int equal = equals(&wallet1, &wallet2);
    printf("Wallets are equal: %d\n", equal);

    subEurosAndCents(&wallet1, 3, 28);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);

    subEurosAndCents(&wallet1, 0, 1);
    print(&wallet1);
}

static void exercise_wallet_03()
{
    Wallet wallet1 = { 123, 45 };
    Wallet wallet2 = { 3, 30 };
    Wallet wallet3 = { 3, 30 };

    print(&wallet1);

    addWallet(&wallet1, &wallet2);
    print(&wallet1);

    addWallet(&wallet1, &wallet3);
    print(&wallet1);

    unsigned long long cents = toCents(&wallet1);
    printf("Cents: %llu\n", cents);
}

static void exercise_wallet_04()
{
    Wallet wallet1 = { 0, 3 };
    Wallet wallet2 = { 0, 1 };

    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);

    subWallet(&wallet1, &wallet2);
    print(&wallet1);
}

void exercise_wallet()
{
    exercise_wallet_01();
    exercise_wallet_02();
    exercise_wallet_03();
    exercise_wallet_04();
}

// =====================================================================================
// End-of-File
// =====================================================================================
