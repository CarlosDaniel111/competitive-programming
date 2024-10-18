#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using edge = tuple<int, int, int>;

#define pb push_back
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x), end(x)
#define ENDL '\n'

vector<string> split(string& s, const string& delimiter) {
  vector<string> tokens;
  size_t pos = 0;
  string token;
  while ((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
  tokens.push_back(s);

  return tokens;
}

tuple<int, int, int> getDate(string s) {
  int dia = stoi(s.substr(0, 2));
  int mes = stoi(s.substr(3, 2));
  int anio = stoi(s.substr(6, 2));

  return {dia, mes, anio};
}

signed main() {
  vector<string> estados = {
      "Aguascalientes",   "Baja California",  "Baja California Sur",
      "Campeche",         "Chiapas",          "Chihuahua",
      "Ciudad de Mexico", "Coahuila",         "Colima",
      "Durango",          "Estado de Mexico", "Guanajuato",
      "Guerrero",         "Hidalgo",          "Jalisco",
      "Michoacan",        "Morelos",          "Nayarit",
      "Nuevo Leon",       "Oaxaca",           "Puebla",
      "Queretaro",        "Quintana Roo",     "San Luis Potosi",
      "Sinaloa",          "Sonora",           "Tabasco",
      "Tamaulipas",       "Tlaxcala",         "Veracruz",
      "Yucatan",          "Zacatecas"};

  vector<string> meses = {"Enero",      "Febrero", "Marzo",     "Abril",
                          "Mayo",       "Junio",   "Julio",     "Agosto",
                          "Septiembre", "Octubre", "Noviembre", "Diciembre"};

  map<string, int> mpState;
  for (auto e : estados) {
    mpState[e] = SZ(mpState);
  }
  map<int, pi> cntByState;
  FOR(i, 0, 32) { cntByState[i] = {0, 0}; }

  vector<map<string, int>> cntByMonth(15);
  map<string, set<pair<string, string>>> cntByBusiness;
  map<string, int> cntBySemester[2];

  int n;
  cin >> n;
  string s;
  getline(cin, s);
  FOR(i, 0, n) {
    getline(cin, s);
    vector<string> inp = split(s, ",");
    int h = stoi(inp[3]), m = stoi(inp[4]);
    cntByState[mpState[inp[0]]].first += h;
    cntByState[mpState[inp[0]]].second += m;

    auto [dia, mes, anio] = getDate(inp[5]);
    cntByMonth[mes - 1][inp[2]] += (h + m);

    cntByBusiness[inp[2]].insert({inp[0], inp[1]});

    cntBySemester[(mes > 6)][inp[2]] += (h + m);
  }

  auto generateReportA = [&]() -> void {
    FOR(i, 0, 32) {
      cout << estados[i] << " " << cntByState[i].first << " "
           << cntByState[i].second << " "
           << cntByState[i].first + cntByState[i].second << ENDL;
    }
  };

  auto generateReportB = [&]() -> void {
    FOR(i, 0, 12) {
      cout << meses[i] << ENDL;
      if (!SZ(cntByMonth[i])) {
        cout << '\t' << "-" << ENDL;
      }
      vector<pair<int, string>> curr;
      for (auto& [emp, cnt] : cntByMonth[i]) {
        curr.pb({-cnt, emp});
      }
      sort(ALL(curr));
      int ant = 1;
      for (auto& [cnt, emp] : curr) {
        if (ant != 1 && cnt != ant) break;
        cout << '\t' << emp << " " << -cnt << ENDL;
        ant = cnt;
      }
    }
  };

  auto generateReportC = [&](int sem) -> void {
    vector<pair<int, string>> curr;
    for (auto& [emp, cnt] : cntBySemester[sem]) {
      curr.pb({-cnt, emp});
    }
    sort(ALL(curr));
    for (auto& [cnt, emp] : curr) {
      cout << emp << " " << -cnt << ENDL;
    }
  };

  auto generateReportD = [&]() -> void {
    vector<pair<int, string>> curr;
    for (auto& [emp, st] : cntByBusiness) {
      curr.pb({-SZ(st), emp});
    }
    sort(ALL(curr));
    for (auto& [cnt, emp] : curr) {
      cout << emp << " " << -cnt << ENDL;
    }
  };

  int t;
  cin >> t;
  while (t--) {
    char c;
    cin >> c;
    if (c == 'A') generateReportA();
    if (c == 'B') generateReportB();
    if (c == 'C') {
      char c2;
      cin >> c2;
      generateReportC(c2 - '0' - 1);
    }
    if (c == 'D') generateReportD();
    cout << ENDL;
  }

  return 0;
}