/* XiangGuHuaJi 2016, game.h
 * 
 */

#ifndef _XIANGGUHUAJI_GAME_H__
#define _XIANGGUHUAJI_GAME_H__

#define GAME_DEBUG

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "definition.h"
#include "map.h"
#include "converter.hpp"

using std::vector;

namespace XGHJ {
class Game
{
public:
    Game(Map& map, int playersize);
    ~Game();

    bool Start();
	bool Run(vector<cv::Mat/*TMilitary*/> &         MilitaryCommandList,
		vector<vector<TDiplomaticCommand> > &       DiplomaticCommandMap);
    bool ConstructionPhase(vector<cv::Mat/*TMilitary*/> &       MilitaryCommandList);
    bool DiplomacyPhase(vector<vector<TDiplomaticCommand> > &   DiplomaticCommandMap);
    bool MilitaryPhase(vector<cv::Mat/*TMilitary*/> &           MilitaryCommandList);
    bool ProducingPhase();
    bool CheckWinner();

    Map& map;

    //TODO move these constant to somewhere else
	const static TRound     MAX_ROUND;
    const static TMilitary  MAX_MILITARY;
    const static TSaving    UNIT_SAVING;
    const static TSaving    UNIT_CITY_INCOME;
	const static TRound     TRUCE_TIME;
	const static float		CORRUPTION_COEF;
	const static float		DEPRECIATION_COEF;

	//first_class statistics
	inline vector<cv::Mat>		getMilitaryMap()	 {return  MilitaryMap_		;}
	inline cv::Mat/*CV_TId*/	getGlobalMap()		 {return  GlobalMap_		;}
	inline vector<TPlayerInfo>	getPlayerInfoList()	 {return  PlayerInfoList_	;}
	inline vector<vector<TDiplomaticStatus> >									
								getDiplomacy()		 {return  Diplomacy_		;}
	inline TRound				getRound()			 {return  Round  			;}
	inline TId					getPlayerSize() 	 {return  PlayerSize		;}
	inline bool					isValid() 			 {return  isValid_      	;}
	//second_class statistics resolved											
	inline vector<cv::Mat>		getOwnershipMasks()	 {return  OwnershipMasks_	;}
	inline vector<cv::Mat>		getAttackPointsMap() {return  AttackPointsMap_	;}
	inline cv::Mat				getDefensePointsMap(){return  DefensePointsMap_	;}
protected:
	//first_class statistics
	vector<cv::Mat>     MilitaryMap_;
	cv::Mat/*CV_TId*/	GlobalMap_;
	vector<TPlayerInfo>	PlayerInfoList_;
	vector<vector<TDiplomaticStatus> >	Diplomacy_;
	TRound              Round;
	TId                 PlayerSize;
	bool                isValid_;
	//second_class statistics resolved
	vector<cv::Mat>     OwnershipMasks_;
    vector<cv::Mat>     AttackPointsMap_;
    cv::Mat             DefensePointsMap_;
private:
    vector<vector<unsigned char> >  TruceTreaty;
};

}


#endif
