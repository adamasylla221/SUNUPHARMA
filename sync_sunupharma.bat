@echo off
setlocal

:: === Configuration ===
set "PROJECT_PATH=C:\Users\DELL\Desktop\L1 GL COURS\Langage C L1\sunupharma-main"
set "GIT_URL=https://github.com/adamasylla221/SUNUPHARMA.git"
set "BRANCH=main"

echo ==============================
echo   🚀 SYNC SUNUPHARMA V1.0
echo ==============================

:: === Aller dans le dossier du projet ===
cd /d "%PROJECT_PATH%" || (
    echo ❌ Erreur : Dossier introuvable : %PROJECT_PATH%
    pause
    exit /b
)

:: === Initialiser Git s'il n'existe pas déjà ===
if not exist ".git" (
    echo 🔧 Initialisation du dépôt Git...
    git init
)

:: === Ajouter ou mettre à jour le remote ===
echo 🔗 Configuration du dépôt distant...
git remote remove origin 2>nul
git remote add origin %GIT_URL%

:: === Récupérer le contenu distant ===
echo 📥 Fusion avec le dépôt distant (si contenu existant)...
git pull origin %BRANCH% --allow-unrelated-histories

:: === Ajouter les fichiers locaux ===
echo 📂 Ajout des fichiers locaux...
git add .

:: === Commit local ===
echo 📝 Création du commit...
git commit -m "Synchronisation locale avec le dépôt distant" || echo (aucune modification à valider)

:: === Pousser sur GitHub ===
echo 🚀 Envoi vers GitHub...
git branch -M %BRANCH%
git push -u origin %BRANCH%

echo.
echo ✅ Synchronisation terminée avec succès !
pause

