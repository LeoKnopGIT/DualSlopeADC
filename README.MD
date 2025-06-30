
# DualSlopeADC

Ein 12-Bit-Dual-Slope-ADC mit CH32V003 Mikrocontroller und 4-stelligem 7-Segment-Display zur Anzeige der gemessenen Gleichspannung.

![Projektübersicht](images/INT.png)
![Projektübersicht](images/DIG.png)

## 🔧 Projektüberblick

Dieses Projekt implementiert einen Dual-Slope-Analog-Digital-Wandler (ADC), wie er z. B. in Digitalmultimetern zum Einsatz kommt. Die Schaltung misst Eingangsspannungen im Bereich von 0–3.3 V und visualisiert das Ergebnis auf einem 7-Segment-Display.


## ⚙️ Hardware

| Komponente       | Beschreibung                  |
|------------------|-------------------------------|
| Mikrocontroller  | CH32V003 (RISC-V, 48 MHz)     |
| Anzeige          | 4-stelliges 7-Segment-Display |
| Betriebsspannung | 3.3 V                         |
| Auflösung        | 12 Bit (theoretisch)          |
| Zeitauflösung    | ~20 ns (Timer mit 48 MHz)     |

![Schaltung](images/PCB.png)

## 📐 Funktionsweise

### ⏱ Prinzip: Dual-Slope-Wandlung

1. **Integration (Messphase):**  
   Eingangsspannung wird über ein RC-Glied integriert  
   → Spannungsanstieg proportional zu \( V_{in} - V_{off} \)

2. **Gegenintegration (Referenzphase):**  
   Eine konstante Referenzspannung wird integriert, bis der Ausgang wieder 0 V erreicht.

3. **Zeitmessung:**  
   Die Dauer dieser Rücklaufphase ist proportional zur Eingangsspannung.

![Simulation](Images/oszi.png)

### Simulation
![Simulation](Images/Sim.png)

