#include <iostream>
#include <ostream>
#include <vector>

/**
 * watchexec --exts cpp "g++ file.cpp && ./a.out"
 */

/**
You have been tasked with writing a program for a popular bank that will
automate all its incoming transactions (transfer, deposit, and withdraw). The
bank has n accounts numbered from 1 to n. The initial balance of each account is
stored in a 0-indexed integer array balance, with the (i + 1)th account having
an initial balance of balance[i].

Execute all the valid transactions. A transaction is valid if:

The given account number(s) are between 1 and n, and
The amount of money withdrawn or transferred from is less than or equal to the
balance of the account. Implement the Bank class:

Bank(long[] balance) Initializes the object with the 0-indexed integer array
balance. boolean transfer(int account1, int account2, long money) Transfers
money dollars from the account numbered account1 to the account numbered
account2. Return true if the transaction was successful, false otherwise.
boolean deposit(int account, long money) Deposit money dollars into the account
numbered account. Return true if the transaction was successful, false
otherwise. boolean withdraw(int account, long money) Withdraw money dollars from
the account numbered account. Return true if the transaction was successful,
false otherwise.


Example 1:

Input
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
Output
[null, true, true, true, false, false]

Explanation
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it
is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it
is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10
+ $20 = $30. bank.deposit(5, 20);     // return true, it is valid to deposit $20
to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is
$10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does
not exist.
*/

using namespace std;

class Bank {
public:
  vector<long long> balance;

  Bank(vector<long long> &balance) {
    // accounts from 1 to n
    this->balance = balance;
  }

  bool validAccountId(int x) {
    if (x < 1 || x >= balance.size() + 1) {
      std::clog << "Invalid account: " << x << '\n';
      return false;
    }
    return true;
  }

  bool checkBalance(int account, long long amount) {
    const long long totalAccountBalance = balance[account - 1];
    if (amount <= totalAccountBalance) {
      return true;
    }
    return false;
  }

  bool transfer(int account1, int account2, long long money) {
    if (!validAccountId(account1) || !validAccountId(account2)) {
      return false;
    }

    if (money < 0) {
      return false;
    }

    if (checkBalance(account1, money)) {
      balance[account1 - 1] -= money;
      balance[account2 - 1] += money;
      return true;
    } else {
      return false;
    }
  }

  bool deposit(int account, long long money) {
    if (!validAccountId(account)) {
      return false;
    }

    if (money < 0) {
      return false;
    }

    balance[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (!validAccountId(account)) {
      return false;
    }

    if (money < 0) {
      return false;
    }

    if (checkBalance(account, money)) {
      balance[account - 1] -= money;
      return true;
    }

    return false;
  }

  friend std::ostream &operator<<(std::ostream &os, const Bank &bank);
};

std::ostream &operator<<(std::ostream &os, const Bank &bank) {
  os << "Bank balance: \n";
  for (int i = 0; i < bank.balance.size(); i++) {
    os << "Account " << i + 1 << " : " << bank.balance[i] << " $" << '\n';
  }
  return os;
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main(int argc, char *argv[]) {
  std::vector<long long> balance = {10, 100, 20, 50, 30};

  Bank *obj = new Bank(balance);

  std::cout << *obj;
  bool ope1 = obj->withdraw(3, 10);
  bool ope2 = obj->transfer(5, 1, 20);
  bool op3 = obj->deposit(5, 20);
  bool ope3 = obj->transfer(3, 4, 15);
  bool ope4 = obj->withdraw(10, 50);
  std::cout << *obj;
  std::cout << std::boolalpha << ope1 << ',' << ope2 << ',' << op3 << ','
            << ope3 << ',' << ope4 << '\n';

  return 0;
}
