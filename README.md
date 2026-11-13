# Conception de projets embarqués

Ce dépôt rassemble des projets de conception embarquée autour d'Arduino. Chaque projet est présenté dans son propre dossier avec son code, son montage Proteus, une image d'illustration et un README contenant une courte description.

## Projets

| Projet | Description |
|---|---|
| [Calculatrice](Projets/calculatrice/README.md) | Calculatrice Arduino commandée par clavier et affichée sur LCD. |
| [Compteur d'éclairage ambiant et régulateur de température](Projets/compteur-pour-l-eclairage-ambiant-et-le-regulateur-de-temperature/README.md) | Projet de comptage et de gestion de l'éclairage et de la température. |
| [Contrôle de feux de circulation](Projets/controle-de-feux-de-circulation/README.md) | Commande de feux de circulation. |
| [Détecteur de fuite de gaz GPL](Projets/detecteur-de-fuite-de-gaz-gpl/README.md) | Détection de gaz avec signalisation par LCD, LED et buzzer. |
| [Envoi de données GPS via GSM](Projets/envoi-de-donnees-de-localisation-gps-via-gsm/README.md) | Transmission de données de localisation GPS via GSM. |
| [Guide de connexion d'un afficheur LCD 16x2](Projets/guide-de-connexion-d-un-afficheur-lcd-16x2-a-un-arduino/README.md) | Exemple de connexion et de commande d'un écran LCD 16x2. |
| [Horloge numérique — date et heure](Projets/horloge-numerique-date-et-heure/README.md) | Affichage de l'heure et de la date avec un module DS1307. |
| [Projet de capteurs d'eau](Projets/projet-de-capteurs-d-eau/README.md) | Projet de détection lié à l'eau avec affichage et indicateurs. |
| [Système d'irrigation intelligent](Projets/systeme-d-irrigation-intelligent/README.md) | Automatisation d'un système d'irrigation. |
| [Éclairage automatique d'escalier](Projets/systeme-d-eclairage-d-escalier-automatique/README.md) | Commande d'éclairage d'escalier à partir de capteurs infrarouges. |
| [Détection de défauts de câbles souterrains](Projets/systeme-de-detection-de-defauts-de-cables-souterrains-avec-emplacement/README.md) | Détection de défauts de câbles avec affichage et emplacement. |
| [Sécurité IoT à base d'Arduino](Projets/securite-iot-a-la-base-arduino/README.md) | Projet de sécurité et de contrôle autour d'Arduino et de l'IoT. |
| [Bâton intelligent pour aveugle](Projets/un-baton-intelligent-pour-aveugle/README.md) | Aide à la détection d'obstacles avec capteur ultrasonique et buzzer. |
| [Capteur de température](Projets/un-capteur-de-temperature/README.md) | Mesure et affichage d'une valeur de température. |
| [Détecteur de flamme](Projets/un-detecteur-de-flame/README.md) | Détection de flamme avec alerte sonore et affichage. |
| [Feux de signalisation — projet 1](Projets/un-systeme-de-feux-de-signalisation-1/README.md) | Premier exemple de commande de feux de signalisation. |
| [Feux de signalisation — projet 2](Projets/un-systeme-de-feux-de-signalisation-2/README.md) | Deuxième exemple de commande de feux de signalisation. |

## Organisation d'un projet

Chaque sous-dossier de [`Projets/`](Projets/) contient :

- `Code.ino` : le programme Arduino ;
- `Montage.pdsprj` : le projet de simulation Proteus ;
- `image.png` : l'image propre au projet ;
- `README.md` : la description et les liens vers les fichiers.

Ouvrez le fichier Proteus avec une version compatible de Proteus. Pour le code Arduino, ouvrez `Code.ino` dans l'IDE Arduino et vérifiez les bibliothèques et le matériel requis avant de téléverser le programme.
