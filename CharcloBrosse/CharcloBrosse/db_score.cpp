#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <queue>
#include "db_score.h"
#include "typedef.h"

DB_Score::DB_Score()
{

}

std::vector<std::pair<std::string, unsigned int>> DB_Score::loadScores()
{
    std::vector<std::pair<std::string, unsigned int>> scores;
    // Ouvre le fichier en mode lecture.
    std::ifstream file(HIGHSCORES_FILE_PATH);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::string name;
            unsigned int score;

            // Lis le nom et le score de la ligne.
            getline(ss, name, ',');
            ss >> score;

            // Convertir le nom en majuscules
            std::transform(name.begin(), name.end(), name.begin(), ::toupper);

            // Ajoute la paire au vecteur
            scores.push_back(std::make_pair(name, score));
        }

        file.close();
    }

    // Tri le vector en ordre décroissant de scores.
    std::sort(scores.begin(), scores.end(), [](const std::pair<std::string, unsigned int> &a, const std::pair<std::string, unsigned int> &b) {
        return a.second > b.second;
    });

    // Si il y a plus de 10 scores, supprimer les scores en excès.
    if (scores.size() > 10)
    {
        scores.resize(10);
    }

    return scores;
}



void DB_Score::saveScore(std::string theName, unsigned int theScore) {
    std::vector<std::pair<std::string, unsigned int>> scores;

    // Création du flux de fichier
    std::ifstream ifs(HIGHSCORES_FILE_PATH);
    if (!ifs)
    {
        // Le fichier n'existe pas, donc on le crée
        std::ofstream ofs(HIGHSCORES_FILE_PATH);
        ofs.close();
        ifs.open(HIGHSCORES_FILE_PATH);
    }

    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::string name;
        unsigned int score;
        getline(iss, name, ',');
        iss >> score;
        scores.push_back({name, score});
    }

    scores.push_back({theName, theScore});

    // Trier le vecteur en ordre décroissant de score
    std::sort(scores.begin(), scores.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    // Si plus de 10 scores, en supprimer pour ne garder que les 10 premiers
    if (scores.size() > 10) {
        scores.resize(10);
    }

    // Ouverture du flux de sortie, cette fois-ci pour écrire dans le fichier
    std::ofstream ofs(HIGHSCORES_FILE_PATH);
    for (const auto &score : scores) {
        ofs << score.first << "," << score.second << std::endl;
    }
    // j'ai enlevé les fermetures de flux car elles sont automatiques  ala fin de la methode et ca consome moins de rsc comme ça
}


//bool DB_Score::isInTop10(unsigned int theScore) {
//    std::vector<std::pair<std::string, unsigned int>> scores;
//    std::ifstream ifs(HIGHSCORES_FILE_PATH);
//    std::string line;
//    while (std::getline(ifs, line)) {
//        std::istringstream iss(line);
//        std::string name;
//        unsigned int score;
//        getline(iss, name, ',');
//        iss >> score;
//        scores.push_back(std::make_pair(name, score));
//    }
//    ifs.close();

//    // Trier le vecteur en ordre décroissant de score
//    std::sort(scores.begin(), scores.end(), [](std::pair<std::string, unsigned int> &left, std::pair<std::string, unsigned int> &right) {
//        return left.second > right.second;
//    });

//    bool isInTop10 = false;

//    // Si moins de 10 scores, le score est forcément dans le top 10
//    if (scores.size() < 10) {
//        isInTop10 = true;
//    } else {
//        // Si plus de 10 scores, en supprimer pour ne garder que les 10 premiers
//        scores.resize(10);

//        // Vérifier si le score est dans le top 10
//        isInTop10 = std::any_of(scores.begin(), scores.end(), [&theScore](const std::pair<std::string, unsigned int>& pair){
//            return pair.second < theScore;
//        });
//    }

//    return isInTop10;
//}
bool DB_Score::isInTop10(unsigned int theScore) {
    // Définir un tas min avec une taille maximale de 10
    std::priority_queue<std::pair<std::string, unsigned int>, std::vector<std::pair<std::string, unsigned int>>, CompareScore> minHeap;

    std::ifstream ifs(HIGHSCORES_FILE_PATH);
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::string name;
        unsigned int score;
        getline(iss, name, ',');
        iss >> score;

        // Ajouter le score au tas min
        minHeap.push(std::make_pair(name, score));

        // Si plus de 10 scores, supprimer le plus petit
        if (minHeap.size() > 10) {
            minHeap.pop();
        }
    }
    ifs.close();

    // Vérifier si le score serait dans le top 10
    return minHeap.size() < 10 || theScore > minHeap.top().second;
}
