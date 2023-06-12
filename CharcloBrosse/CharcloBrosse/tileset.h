/**
 * @file tileset.h
 * @brief Header file for class Tileset
 * @author Melvin WARNET
 * @date 05/06/2023
 * @version 1.2
 */
#ifndef TILESET_H
#define TILESET_H

#include <QPixmap>
#include <string>


/**
 * @class Tileset class
 * @brief The Tileset class generate and stock all images of the game
 * Functions of Tileset class give access to images wanted. Reed documentation to know how to get a specified image.
 */
class TileSet
{
private:

    QPixmap* itsPlayerRightTilesList[3][2]; /**< The array that contains images of Player in direction RIGHT, [0][n] for running animation, [1][n] for jumping animation, [2][n] for hitting animation, [n][0] for frame 1, [n][1] for frame 2 */
    QPixmap* itsEnemyRightTilesList[5][3][2]; /**< The array that contains images of Enemies in direction RIGHT, [0][n][n] for Standard, [1][n][n] for Accelerator1, [2][n][n] for Accelerator2, [3][n][n] for Accelerator3, [4][n][n] for Giant, [n][0][n] for running animation, [n][1][n] for jumping image, [n][2][n] for hitted animation, [n][n][0] for frame 1, [n][n][1] for frame 2 */
    QPixmap* itsPlayerLeftTilesList[3][2]; /**< The array that contains images of Player in direction RIGHT, [0][n] for running animation, [1][n] for jumping animation, [2][n] for hitting animation, [n][0] for frame 1, [n][1] for frame 2 */
    QPixmap* itsEnemyLeftTilesList[5][3][2]; /**< The array that contains images of Enemies in direction RIGHT, [0][n][n] for Standard, [1][n][n] for Accelerator1, [2][n][n] for Accelerator2, [3][n][n] for Accelerator3, [4][n][n] for Giant, [n][0][n] for running animation, [n][1][n] for jumping image, [n][2][n] for hitted animation, [n][n][0] for frame 1, [n][n][1] for frame 2 */
    QPixmap* itsBlockTilesList[2]; /**< The array that contains images of a Block, [0] for Block in basic state image, [1] for Block in hit state */
    QPixmap* itsGroundTile; /**< The image of a ground Block */
    QPixmap* itsPOWTilesList[2]; /**< The array that contains images of a POW, [0] for POW in normal state image, [1] for POW in hit state image */
    QPixmap* itsObstacleTile; /**< The array that contains images of an Obstacle */
    QPixmap* itsMoneyTilesList[3][2];/**< The array that contains images of Money, [0][n] for Yellow Coin animation, [1][n] for Red Coin animation, [2][n] for Bill animation, [n][0] for frame 1, [n][1] for frame 2 */
    QPixmap* itsSpawnerTilesList[2]; /**< The array that contains images of a Spawner, [0] for left Spawner, [1] for right Spawner */
    QPixmap* itsDespawnerTilesList[2]; /**< The array that contains images of a Despawner, [0] for left Spawner, [1] for right Spawner */
    QPixmap* itsNoTextureTile; /**< The image to display if a texture is not found */
    QPixmap* itsBackground;/**< The image of the background */

public:
    /**
     * @brief Tileset class constructor declaration
     * Generate and stock all images from the file specified
     * @param string aFilePath : The path to the file which contains all images (tileset)
     */
    TileSet(std::string aTileSetFilePath, std::string aBackgroundFilePath);

    /**
     * @brief Tileset::getItsPlayerRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of the Player while is running at the frame wanted
     */
    QPixmap* getItsPlayerRunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsPlayerJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of the Player while is jumping
     */
    QPixmap* getItsPlayerJumpingRightTile();

    /**
     * @brief Tileset::getItsPlayerHittingTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of the Player while is hitting at the frame wanted
     */
    QPixmap* getItsPlayerHittingRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsPlayerRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of the Player while is running at the frame wanted
     */
    QPixmap* getItsPlayerRunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsPlayerJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of the Player while is jumping
     */
    QPixmap* getItsPlayerJumpingLeftTile();

    /**
     * @brief Tileset::getItsPlayerHittingTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of the Player while is hitting at the frame wanted
     */
    QPixmap* getItsPlayerHittingLeftTile(unsigned short aFrame);






    /**
     * @brief Tileset::getItsEnemyStandardRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in running at the frame wanted
     */
    QPixmap* getItsEnemyStandardRunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyStandardJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in jumping
     */
    QPixmap* getItsEnemyStandardJumpingRightTile();

    /**
     * @brief Tileset::getItsEnemyStandardHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in hitted at the frame wanted
     */
    QPixmap* getItsEnemyStandardHittedRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyStandardRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in running at the frame wanted
     */
    QPixmap* getItsEnemyStandardRunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyStandardJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in jumping
     */
    QPixmap* getItsEnemyStandardJumpingLeftTile();

    /**
     * @brief Tileset::getItsEnemyStandardHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Standard in hitted at the frame wanted
     */
    QPixmap* getItsEnemyStandardHittedLeftTile(unsigned short aFrame);





    /**
     * @brief Tileset::getItsEnemyAccelerator1RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator1 while is running state 1 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator1RunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator1JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping
     */
    QPixmap* getItsEnemyAccelerator1JumpingRightTile();

    /**
     * @brief Tileset::getItsEnemyAcceleratorHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator iwhile is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator1HittedRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator1RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator1 while is running state 1 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator1RunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator1JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping
     */
    QPixmap* getItsEnemyAccelerator1JumpingLeftTile();

    /**
     * @brief Tileset::getItsEnemyAcceleratorHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator iwhile is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator1HittedLeftTile(unsigned short aFrame);




    /**
     * @brief Tileset::getItsEnemyAccelerator2RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 2 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator2RunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator2JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping
     */
    QPixmap* getItsEnemyAccelerator2JumpingRightTile();

    /**
     * @brief Tileset::getItsEnemyAccelerator2HittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator2HittedRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator2RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 2 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator2RunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator2JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is jumping
     */
    QPixmap* getItsEnemyAccelerator2JumpingLeftTile();

    /**
     * @brief Tileset::getItsEnemyAccelerator2HittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state2 while is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator2HittedLeftTile(unsigned short aFrame);





    /**
     * @brief Tileset::getItsEnemyAccelerator3RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 3 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator3RunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator3JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state3 while is jumping
     */
    QPixmap* getItsEnemyAccelerator3JumpingRightTile();

    /**
     * @brief Tileset::getItsEnemyAccelerator3HittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state 3 while is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator3HittedRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator3RunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator while is running state 3 at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator3RunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyAccelerator3JumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state3 while is jumping
     */
    QPixmap* getItsEnemyAccelerator3JumpingLeftTile();

    /**
     * @brief Tileset::getItsEnemyAccelerator3HittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Accelerator in state 3 while is hitted at the frame wanted
     */
    QPixmap* getItsEnemyAccelerator3HittedLeftTile(unsigned short aFrame);





    /**
     * @brief Tileset::getItsEnemyGiantRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in running at the frame wanted
     */
    QPixmap* getItsEnemyGiantRunningRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyGiantJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in jumping
     */
    QPixmap* getItsEnemyGiantdJumpingRightTile();

    /**
     * @brief Tileset::getItsEnemyGiantHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in hitted at the frame wanted
     */
    QPixmap* getItsEnemyGiantHittedRightTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyGiantRunningTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in running at the frame wanted
     */
    QPixmap* getItsEnemyGiantRunningLeftTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsEnemyGiantJumpingTile() function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in jumping
     */
    QPixmap* getItsEnemyGiantdJumpingLeftTile();

    /**
     * @brief Tileset::getItsEnemyGiantHittedTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Enemy Giant in hitted at the frame wanted
     */
    QPixmap* getItsEnemyGiantHittedLeftTile(unsigned short aFrame);




    /**
     * @brief Tileset::getItsBlockTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block in a normal state
     */
    QPixmap* getItsBlockTile();

    /**
     * @brief Tileset::getItsBlockHittedTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block in a hit state
     */
    QPixmap* getItsBlockHittedTile();




    /**
     * @brief Tileset::getItsGroundTile() function declaration
     * @return QPixmap* : A pointer to the image of a ground Block
     */
    QPixmap* getItsGroundTile();




    /**
     * @brief Tileset::getItsPOWBlockTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block_POW in a normal state
     */
    QPixmap* getItsPOWBlockTile();

    /**
     * @brief Tileset::getItsPOWBlockHittedTile() function declaration
     * @return QPixmap* : A pointer to the image of a Block_POW in a hit state
     */
    QPixmap* getItsPOWBlockHittedTile();




    /**
     * @brief Tileset::getItsObstacleTile() function declaration
     * @return QPixmap* : A pointer to the image of an Obstacle
     */
    QPixmap* getItsObstacleTile();




    /**
     * @brief Tileset::getItsRedCoinTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Red Coin at the frame wanted
     */
    QPixmap* getItsRedCoinTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsYellowCoinTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of an Yellow Coin at the frame wanted
     */
    QPixmap* getItsYellowCoinTile(unsigned short aFrame);

    /**
     * @brief Tileset::getItsBillTile(unsigned short aFrame) function declaration
     * @return QPixmap* : A pointer to the image of a bill at the frame wanted
     */
    QPixmap* getItsBillTile(unsigned short aFrame);




    /**
     * @brief Tileset::getItsSpawnerTile(unsigned short index) function declaration
     * @param unsigned short index : The index of the image you want, index=[0] for left Spawner image, index=[1] for right Spawner image
     * @return QPixmap* : A pointer to the image of a Spawner specified
     */
    QPixmap* getItsSpawnerTile(unsigned short index);




    /**
     * @brief Tileset::getItsDespawnerTile(unsigned short index) function declaration
     * @param unsigned short index : The index of the image you want, index=[0] for left Despawner image, index=[1] for right Despawner image
     * @return QPixmap* : A pointer to the image of a Despawner specified
     */
    QPixmap* getItsDespawnerTile(unsigned short index);




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

};

#endif // TILESET_H
