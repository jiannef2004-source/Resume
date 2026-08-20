# Engineering Analysis Toolkit

A small Python/Streamlit toolkit for transparent electrical-engineering calculations, including DC power, 4–20 mA process scaling, RC time constants, and voltage-divider analysis.

## Features

- DC power and equivalent resistance calculations.
- 4–20 mA current-loop scaling into engineering units.
- RC time-constant and approximate 5τ settling-time calculations.
- Voltage-divider calculations.
- Calculation logic separated from the UI for easier testing and review.

## Run locally

```bash
pip install streamlit
streamlit run app/main.py
```
