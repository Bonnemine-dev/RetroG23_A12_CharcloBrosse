/**
 * @file tileset.h
 * @brief Header file for class TileSet
 * @date 05/06/2023
 * @version 2.0
 */
#ifndef TILESET_H
#define TILESET_H

#include <QPixmap>
#include <string>
#include <array>


/**
 * @class TileSet class
 * @brief The TileSet class generate and stock all images of the game
 * Functions of TileSet class give access to images wanted. Reed documentation to know how to get a specified image.
 */
class TileSet
{
private:
    /**
     * @brief itsPlayerTilesList the player sprites list
     */
    static std::array<QPixmap*, 12> itsPlayerTilesList;
    /**
     * @brief itsEnnemyStandardTilesList the standard enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyStandardTilesList;
    /**
     * @brief itsEnnemyAcceleratorTilesList the accelerator enemy sprites
     */
    static std::array<std::array<QPixmap*, 12>*, 3> itsEnnemyAcceleratorTilesList;
    /**
     * @brief itsEnnemyGiantTilesList the giant enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyGiantTilesList;
    /**
     * @brief itsEnnemyJumperTilesList the jumper enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyJumperTilesList;
    /**
     * @brief itsEnnemyFreezerTilesList the freezer enemy sprites
     */
    static std::array<QPixmap*, 12> itsEnnemyFreezerTilesList;
    /**
     * @brief itsBlockTilesList the blocks sprites
     */
    static std::array<QPixmap*, 6> itsBlockTilesList;
    /**
     * @brief itsNoTextureTile texture with no sprites
     */
    static QPixmap *itsNoTextureTile;
    /**
     * @brief itsBackground the background
     */
    static QPixmap *itsBackground;
    /**
     * @brief itsMoneyTilesList the moneys sprites
     */
    static std::array<std::array<QPixmap*, 2>*, 3> itsMoneyTilesList;
    /**
     * @brief itsSpawnerTilesList the spawners sprites
     */
    static std::array<QPixmap*, 2> itsSpawnerTilesList;
    /**
     * @brief itsDespawnerTilesList the despawners sprites
     */
    static std::array<QPixmap*, 2> itsDespawnerTilesList;


//    std::array<QPixmap*, >* itsPlayerTilesList;



//    QPixmap* itsPlayerRightTilesList[3][2]; /**< The array that contains images of Player in direction RIGHT, [0][n] for running animation, [1][n] for jumping animation, [2][n] for hitting animation, [n][0] for frame 1, [n][1] for frame 2 */
//    QPixmap* itsEnemyRightTilesList[5][3][2]; /**< The array that contains images of Enemies in direction RIGHT, [0][n][n] for Standard, [1][n][n] for Accelerator1, [2][n][n] for Accelerator2, [3][n][n] for Accelerator3, [4][n][n] for Giant, [n][0][n] for running animation, [n][1][n] for jumping image, [n][2][n] for hitted animation, [n][n][0] for frame 1, [n][n][1] for frame 2 */
//    QPixmap* itsPlayerLeftTilesList[3][2]; /**< The array that contains images of Player in direction Left, [0][n] for running animation, [1][n] for jumping animation, [2][n] for hitting animation, [n][0] for frame 1, [n][1] for frame 2 */
//    QPixmap* itsEnemyLeftTilesList[5][3][2]; /**< The array that contains images of Enemies in direction Left, [0][n][n] for Standard, [1][n][n] for Accelerator1, [2][n][n] for Accelerator2, [3][n][n] for Accelerator3, [4][n][n] for Giant, [n][0][n] for running animation, [n][1][n] for jumping image, [n][2][n] for hitted animation, [n][n][0] for frame 1, [n][n][1] for frame 2 */
//    QPixmap* itsBlockTilesList[2]; /**< The array that contains images of a Block, [0] for Block in basic state image, [1] for Block in hit state */
//    QPixmap* itsGroundTile; /**< The image of a ground Block */
//    QPixmap* itsPOWTilesList[2]; /**< The array that contains images of a POW, [0] for POW in normal state image, [1] for POW in hit state image */
//    QPixmap* itsObstacleTile; /**< The array that contains images of an Obstacle */
//    QPixmap* itsMoneyTilesList[3][2];/**< The array that contains images of Money, [0][n] for Yellow Coin animation, [1][n] for Red Coin animation, [2][n] for Bill animation, [n][0] for frame 1, [n][1] for frame 2 */
//    QPixmap* itsSpawnerTilesList[2]; /**< The array that contains images of a Spawner, [0] for left Spawner, [1] for right Spawner */
//    QPixmap* itsDespawnerTilesList[2]; /**< The array that contains images of a Despawner, [0] for left Spawner, [1] for right Spawner */
//    QPixmap* itsNoTextureTile; /**< The image to display if a texture is not found */
//    QPixmap* itsBackground;/**< The image of the background */

public:
    /**
     * @brief Tileset class constructor declaration
     * Generate and stock all images from the file specified
     * @param string aFilePath : The path to the file which contains all images (tileset)
     */
    TileSet(std::string aTileSetFilePath);


//    /**
//     * @brief Tileset::getItsPlayerRunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is running in right direction at the frame wanted
//     */
//    QPixmap* getItsPlayerRunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsPlayerJumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is jumping in right direction
//     */
//    QPixmap* getItsPlayerJumpingRightTile();

//    /**
//     * @brief Tileset::getItsPlayerHittingRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is hitting in right direction at the frame wanted
//     */
//    QPixmap* getItsPlayerHittingRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsPlayerRunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is running in left direction at the frame wanted
//     */
//    QPixmap* getItsPlayerRunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsPlayerJumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is jumping in left direction
//     */
//    QPixmap* getItsPlayerJumpingLeftTile();

//    /**
//     * @brief Tileset::getItsPlayerHittingLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of the Player while is hitting in left direction at the frame wanted
//     */
//    QPixmap* getItsPlayerHittingLeftTile(unsigned short aFrame);






//    /**
//     * @brief Tileset::getItsEnemyStandardRunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in running in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyStandardRunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyStandardJumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in jumping in right direction
//     */
//    QPixmap* getItsEnemyStandardJumpingRightTile();

//    /**
//     * @brief Tileset::getItsEnemyStandardHittedRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in hitted in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyStandardHittedRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyStandardRunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in running in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyStandardRunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyStandardJumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in jumping in left direction
//     */
//    QPixmap* getItsEnemyStandardJumpingLeftTile();

//    /**
//     * @brief Tileset::getItsEnemyStandardHittedLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Standard in hitted in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyStandardHittedLeftTile(unsigned short aFrame);





//    /**
//     * @brief Tileset::getItsEnemyAccelerator1RunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator1 while is running in right direction state 1 at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator1RunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator1JumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping in right direction
//     */
//    QPixmap* getItsEnemyAccelerator1JumpingRightTile();

//    /**
//     * @brief Tileset::getItsEnemyAcceleratorHittedRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator iwhile is hitted in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator1HittedRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator1RunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator1 while is running state 1 in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator1RunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator1JumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping in left direction
//     */
//    QPixmap* getItsEnemyAccelerator1JumpingLeftTile();

//    /**
//     * @brief Tileset::getItsEnemyAcceleratorHittedLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator iwhile is hitted in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator1HittedLeftTile(unsigned short aFrame);




//    /**
//     * @brief Tileset::getItsEnemyAccelerator2RunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running in right direction state 2 at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator2RunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator2JumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping in right direction
//     */
//    QPixmap* getItsEnemyAccelerator2JumpingRightTile();

//    /**
//     * @brief Tileset::getItsEnemyAccelerator2HittedRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is hitted in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator2HittedRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator2RunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 2 in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator2RunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator2JumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 in left direction while is jumping
//     */
//    QPixmap* getItsEnemyAccelerator2JumpingLeftTile();

//    /**
//     * @brief Tileset::getItsEnemyAccelerator2HittedLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is hitted in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator2HittedLeftTile(unsigned short aFrame);





//    /**
//     * @brief Tileset::getItsEnemyAccelerator3RunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 3 in right direction  at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator3RunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator3JumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state3 while is jumping in right direction
//     */
//    QPixmap* getItsEnemyAccelerator3JumpingRightTile();

//    /**
//     * @brief Tileset::getItsEnemyAccelerator3HittedRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state 3 while is hitted in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator3HittedRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator3RunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 3 in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator3RunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyAccelerator3JumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state3 while is jumping in left direction
//     */
//    QPixmap* getItsEnemyAccelerator3JumpingLeftTile();

//    /**
//     * @brief Tileset::getItsEnemyAccelerator3HittedLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state 3 while is hitted in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyAccelerator3HittedLeftTile(unsigned short aFrame);





//    /**
//     * @brief Tileset::getItsEnemyGiantRunningRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in running in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyGiantRunningRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyGiantJumpingRightTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in jumping in right direction
//     */
//    QPixmap* getItsEnemyGiantdJumpingRightTile();

//    /**
//     * @brief Tileset::getItsEnemyGiantHittedRightTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in hitted in right direction at the frame wanted
//     */
//    QPixmap* getItsEnemyGiantHittedRightTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyGiantRunningLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in running in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyGiantRunningLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsEnemyGiantJumpingLeftTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in jumping in left direction
//     */
//    QPixmap* getItsEnemyGiantdJumpingLeftTile();

//    /**
//     * @brief Tileset::getItsEnemyGiantHittedLeftTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Enemy Giant in hitted in left direction at the frame wanted
//     */
//    QPixmap* getItsEnemyGiantHittedLeftTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsBlockTile() function declaration
//     * @return QPixmap* : A pointer to the image of a Block in a normal state
//     */
//    QPixmap* getItsBlockTile();

//    /**
//     * @brief Tileset::getItsBlockHittedTile() function declaration
//     * @return QPixmap* : A pointer to the image of a Block in a hit state
//     */
//    QPixmap* getItsBlockHittedTile();




//    /**
//     * @brief Tileset::getItsGroundTile() function declaration
//     * @return QPixmap* : A pointer to the image of a ground Block
//     */
//    QPixmap* getItsGroundTile();




//    /**
//     * @brief Tileset::getItsPOWBlockTile() function declaration
//     * @return QPixmap* : A pointer to the image of a Block_POW in a normal state
//     */
//    QPixmap* getItsPOWBlockTile();

//    /**
//     * @brief Tileset::getItsPOWBlockHittedTile() function declaration
//     * @return QPixmap* : A pointer to the image of a Block_POW in a hit state
//     */
//    QPixmap* getItsPOWBlockHittedTile();




//    /**
//     * @brief Tileset::getItsObstacleTile() function declaration
//     * @return QPixmap* : A pointer to the image of an Obstacle
//     */
//    QPixmap* getItsObstacleTile();




//    /**
//     * @brief Tileset::getItsRedCoinTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Red Coin at the frame wanted
//     */
//    QPixmap* getItsRedCoinTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsYellowCoinTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of an Yellow Coin at the frame wanted
//     */
//    QPixmap* getItsYellowCoinTile(unsigned short aFrame);

//    /**
//     * @brief Tileset::getItsBillTile(unsigned short aFrame) function declaration
//     * @return QPixmap* : A pointer to the image of a bill at the frame wanted
//     */
//    QPixmap* getItsBillTile(unsigned short aFrame);




//    /**
//     * @brief Tileset::getItsSpawnerTile(unsigned short index) function declaration
//     * @param unsigned short index : The index of the image you want, index=[0] for left Spawner image, index=[1] for right Spawner image
//     * @return QPixmap* : A pointer to the image of a Spawner specified
//     */
//    QPixmap* getItsSpawnerTile(unsigned short index);




//    /**
//     * @brief Tileset::getItsDespawnerTile(unsigned short index) function declaration
//     * @param unsigned short index : The index of the image you want, index=[0] for left Despawner image, index=[1] for right Despawner image
//     * @return QPixmap* : A pointer to the image of a Despawner specified
//     */
//    QPixmap* getItsDespawnerTile(unsigned short index);

    /**
     * @brief Tileset::getItsNoTextureTile() function declaration
     * @return QPixmap* : A pointer to the the default image
     */
    QPixmap* getItsNoTextureTile();

    /**
     * @brief Tileset::getItsBackground() function declaration
     * @return QPixmap* : A pointer to the background image
     */
    QPixmap* getItsBackground();
    /**
     * @brief getItsPlayerTilesList gets itsPlayerList
     * @return the list of all the player sprites
     */
    std::array<QPixmap *, 12> *getItsPlayerTilesList();
    /**
     * @brief getItsEnnemyStandardTilesList gets itsEnemyStandardTilesList
     * @return the list of all the standard enemy sprites
     */
    std::array<QPixmap *, 12> *getItsEnnemyStandardTilesList();
    /**
     * @brief getItsEnnemyAcceleratorTilesList get itsEnemyAcceleratorTilesList
     * @return the list of all the accelerator enemy sprites
     */
    std::array<std::array<QPixmap *, 12> *, 3> *getItsEnnemyAcceleratorTilesList();
    /**
     * @brief getItsEnnemyGiantTilesList gets itsEnemyGiantTilesList
     * @return the lits of all the Giant enemy sprites
     */
    std::array<QPixmap *, 12> *getItsEnnemyGiantTilesList();
    /**
     * @brief getItsEnnemyJumperTilesList
     * @return
     */
    std::array<QPixmap *, 12> *getItsEnnemyJumperTilesList();
    /**
     * @brief getItsEnnemyFreezerTilesList
     * @return
     */
    std::array<QPixmap *, 12> *getItsEnnemyFreezerTilesList();
    /**
     * @brief getItsBlockTilesList gets itsBlockTilesList
     * @return the list of all the blocks sprites
     */
    std::array<QPixmap *, 6> *getItsBlockTilesList();
    /**
     * @brief getItsMoneyTilesList gets itsMoneyTilesList
     * @return the list of all the moneys sprites
     */
    std::array<std::array<QPixmap *, 2> *, 3> *getItsMoneyTilesList();
    /**
     * @brief getItsSpawnerTilesList gets itsSpawnerTilesList
     * @return the list of all the spawners sprites
     */
    std::array<QPixmap *, 2> *getItsSpawnerTilesList();
    /**
     * @brief getItsDespawnerTilesList gets itsDespawnerTilesList
     * @return the list of all the despawners sprites
     */
    std::array<QPixmap *, 2> *getItsDespawnerTilesList();

};

#endif // TILESET_H
