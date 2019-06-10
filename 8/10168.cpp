#include <iostream>
#include <cstring>
#include <vector>
#define ulli unsigned long long int
#define lli long long int
#define SIZE 1000000
#define MAX_SIZE 10000000

using namespace std;

// int results[SIZE][4];
vector<int> primes;
bool is_prime0[SIZE];
bool is_prime1[SIZE];
bool is_prime2[SIZE];
bool is_prime3[SIZE];
bool is_prime4[SIZE];
bool is_prime5[SIZE];
bool is_prime6[SIZE];
bool is_prime7[SIZE];
bool is_prime8[SIZE];
bool is_prime9[SIZE];

void setIsPrime(ulli n, bool state) {
  ulli remain = n;
  int counter = 0;
  for(int i = SIZE;remain > i;counter++) {
    remain -= i;
  }
  switch(counter) {
    case 0:
      is_prime0[n % SIZE] = state;
      break;
    case 1:
      is_prime1[n % SIZE] = state;
      break;
    case 2:
      is_prime2[n % SIZE] = state;
      break;
    case 3:
      is_prime3[n % SIZE] = state;
      break;
    case 4:
      is_prime4[n % SIZE] = state;
      break;
    case 5:
      is_prime5[n % SIZE] = state;
      break;
    case 6:
      is_prime6[n % SIZE] = state;
      break;
    case 7:
      is_prime7[n % SIZE] = state;
      break;
    case 8:
      is_prime8[n % SIZE] = state;
      break;
    case 9:
      is_prime9[n % SIZE] = state;
      break;
  }
}

bool getIsPrime(ulli n) {
  ulli remain = n;
  int counter = 0;
  for(int i = SIZE;remain > i;counter++) {
    remain -= i;
  }
  switch(counter) {
    case 0:
      return is_prime0[n % SIZE];
    case 1:
      return is_prime1[n % SIZE];
    case 2:
      return is_prime2[n % SIZE];
    case 3:
      return is_prime3[n % SIZE];
    case 4:
      return is_prime4[n % SIZE];
    case 5:
      return is_prime5[n % SIZE];
    case 6:
      return is_prime6[n % SIZE];
    case 7:
      return is_prime7[n % SIZE];
    case 8:
      return is_prime8[n % SIZE];
    case 9:
      return is_prime9[n % SIZE];
  }

  return false;
}

void sieve() {
  setIsPrime(0, false);
  setIsPrime(1, false);

  for(ulli i = 2;i < MAX_SIZE;i++) {
    if(getIsPrime(i)) {
      primes.push_back(i);
      for(ulli j = i * i;j < MAX_SIZE;j += i) {
        setIsPrime(j, false);
      }
    }
  }
}

int *solve(ulli n, int *results) {

  int primec = primes.size();
  for(ulli i = 0;i < primec;i++) {
    if(n < 2 + primes[i]) {
      return NULL;
    }
    for(ulli j = 0;j < primec;j++) {
      if(n < 2 + primes[i] + primes[j]) {
        return NULL;
      }
      for(ulli k = 0;k < primec;k++) {
        if(n < 2 + primes[i] + primes[j] + primes[k]) {
          break;
        }
        if(getIsPrime(n - primes[i] - primes[j] - primes[k])) {
          results[0] = primes[i];
          results[1] = primes[j];
          results[2] = primes[k];
          results[3] = n - primes[i] - primes[j] - primes[k];

          return &results[0];
        }
      }
    }
  }

  return NULL;
}

void init() {
  memset(is_prime0, true, SIZE);
  memset(is_prime1, true, SIZE);
  memset(is_prime2, true, SIZE);
  memset(is_prime3, true, SIZE);
  memset(is_prime4, true, SIZE);
  memset(is_prime5, true, SIZE);
  memset(is_prime6, true, SIZE);
  memset(is_prime7, true, SIZE);
  memset(is_prime8, true, SIZE);
  memset(is_prime9, true, SIZE);
  primes.clear();
  sieve();
}

int main() {
  ulli n;
  int *p;

  int results[4];
  init();

  while(cin >> n) {
    if(n < 8) {
      cout << "Impossible." << endl;
      continue;
    }

    if((p = solve(n, results)) != NULL) {
      for(int i = 0;i < 3;i++, p++) {
        cout << *p << ' ';
      }
      cout << *p << endl;
    } else {
      cout << "Impossible." << endl;
    }
  }
  return 0;
}
