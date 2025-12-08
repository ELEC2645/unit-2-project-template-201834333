#ifndef FUNCS_H
#define FUNCS_H

/* Menu item handlers */
void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);

/* dBm <-> mW conversion */
double dbm_to_mw(double dbm);
double mw_to_dbm(double mw);

/* Hz <-> rad/s conversion */
double hz_to_rad(double hz);
double rad_to_hz(double rad);

/* Temperature conversions */
double c_to_k(double c);
double k_to_c(double k);
double c_to_f(double c);
double f_to_c(double f);

/* Engineering prefixes */
double apply_prefix(double value, char prefix);

/* History file I/O */
void save_history(double input, double output, const char *inUnit, const char *outUnit);
void show_history(void);

#endif