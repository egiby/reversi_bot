#include "Client.hpp"
#include "NMovesAhead.hpp"

Client client(getStrategy(5));

int main()
{
#ifdef _GEANY
    freopen("log", "w", stderr);
#endif
    client.game();
    return 0;
}
