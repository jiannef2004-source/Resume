# Design Notes

The application separates NMEA parsing from serial I/O so parser behavior can be tested without hardware. RMC sentences are used because they contain receiver status and ground speed in knots. Invalid fixes are surfaced explicitly instead of being treated as zero-speed measurements.

Future improvements could include a graphical dashboard, rolling-average filtering, GPS accuracy metrics, and a wheel-speed sensor for low-speed validation.
