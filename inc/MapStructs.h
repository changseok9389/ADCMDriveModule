#ifndef MAP_STRUCTS_H
#define MAP_STRUCTS_H

#include <cstdint>
#include <vector>
//#include <map>
//#include <unordered_map>

//#define SAVE_GRID_CONNECTIVITY

#if !(defined(_WIN64) || defined(_WIN32))
typedef char				__int8;
typedef short int			__int16;
typedef int					__int32;
typedef long int			__int64;
#endif

typedef unsigned char       byte;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned int		UINT;

//------------------------------------------------------------------------------
//			���� Ÿ��
//------------------------------------------------------------------------------
enum ObjTypeInRoad
{
	OTR_UNKWON,				// 0 : ������ ��ü
	OTR_PREVROAD,			// 1 : ���Ե��� Road ID
	OTR_NEXTROAD,			// 2 : ���⵵�� Road ID
	OTR_LANE,				// 3 : ���� Lane ID
	OTR_LINE,				// 4 : ���� Line ID
	OTR_CROSSWALK,			// 5 : Ⱦ�ܺ��� CrossWalk ID
	OTR_SPEEDBUMP,			// 6 : ���ӹ����� SpeedBump ID
	OTR_TRAFFICLIGHT,		// 7 : ��ȣ�� TrafficLight ID
	OTR_STOPSIGN,			// 8 : ����ǥ���� StopSign ID
	OTR_YIELDSIGN,			// 9 : �纸ǥ���� YieldSign ID
	OTR_LEFTBORDER,			// 10 : ������� Border ID
	OTR_RIGHTBORDER,		// 11 : ������� Border ID
	OTR_NUMBER,				// 12 : ��ü���� ����
};

//------------------------------------------------------------------------------
//			������ ��ǥ��
//------------------------------------------------------------------------------
#pragma pack(push, 1)
typedef struct 
{
	double dx;
	double dy;
	double dz;
} VERTEX_INFO;  //24
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	double dx;
	double dy;
	double dz;
} GEOMETRY;  //24
#pragma pack(pop)

//------------------------------------------------------------------------------
//			����� ����ü
//------------------------------------------------------------------------------
#pragma pack(push, 1)
typedef struct 
{
	__int8				nRoadRank;					// ���� ���
	__int8				nRoadType;					// ���� ����
	__int8				nLinkType;					// ���� ����
	__int8				nMaxSpeed;					// �ְ����Ѽӵ�
	__int8				nLaneNo;					// ���� ��ȣ
	__int8				nPrevLaneNum;				// ���� ���� ����
	__int8				nNextLaneNum;				// ���� ���� ����
	__int8				nLaneIndex;					// ������ ���� ��ȣ
	__int16				nVerticesNum;				// ���ؽ� ����
	float				fLength;					// ����
	__int64				nID;						// ����ID (������)
	__int64				nR_LaneID;					// �������� ID (������)
	__int64				nL_LaneID;					// �������� ID (������)
	__int64				nFromNodeID;				// ������� ID (������)
	__int64				nToNodeID;					// ������� ID (������)
	__int64				nSectionID;					// ����/���� ID (������)
	__int8				nReserved[2];				// -
}LANE_INFO; // 64byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nVerticesNum;			// ���ؽ� ����
	__int16				nType;					// ������ ����
	__int64				nID;					// ������ID (������)
	__int64				nSelectID;				// ���� ID (������)
	UINT				nReserved[3];			// -					
}PARKINGLOT_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nRefLane;				// ���� ���� ��
	__int64				nID;					// ����ǥ��ID (������)
	__int64				nLinkID;				// ��ũ ID (������)
	__int64				nPostID;				// ���� ID (������)
	__int16				nVerticesNum;			// ���ؽ� ����
	char				nReserved[6];			// -
}SIGN_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nVerticesNum;			// ���ؽ� ����
	__int16				nType;					// �� ���, ���� ����
	__int16				nKind;					// �߾Ӽ�, ������������ �� ���� ����
	__int64				nID;						// ����ID (������)
	__int64				nR_LinkID;					// �������� ID  (������)
	__int64				nL_LinkID;					// �������� ID  (������)
	char				nReserved[2];		// -
}LINE_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int8				nType;					// ǥ�� ����
	__int16				nKind;					// ǥ�� ����
	__int16				nVerticesNum;			// ���ؽ� ����
	__int64				nID;					// �ǳθ�ID (������)
	__int64				nLinkID;				// ���� ���� ID (������)
	char				nReserved[11];			// -
}CROSSWALK_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nType;					// ���� ��ȣ�� ����
	__int16				nRefLane;				// ���� ���� ��
	__int64				nID;					// ���� ��ȣ��ID (������)
	__int64				nLinkID;				// ��ũ ID (������)
	__int64				nPostID;				// ���� ID (������)
	UINT				nReserved;				// -		
}SIGNAL_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nVerticesNum;			// ���ؽ� ����
	__int16				nType;					// �ü�����
	__int16				nIsCentral;				// �߾Ӻи���
	__int16				nLowHigh;				// ���, �ϴ�
	__int64				nID;					// ������ȣ�ü�ID (������)
	__int64				nRef_FID;				// ���ϴ� ID (������)
	UINT				nReserved[2];			// -		
}BORDER_INFO; // 32byte
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int16				nVerticesNum;			// ���ؽ� ����
	__int16				nType;					// ���ӹ����� ����
	__int16				nRef_Lane;				// ���� ���� ��
	__int64				nID;					// ���ӹ�����ID (������)
	__int64				nLinkID;				// ��ũID (������)
	char				nReserved[10];			// -
}SPEEDBUMP_INFO; // 32byte
#pragma pack(pop)

//------------------------------------------------------------------------------
//			(��ü ���� + ���� ����) ����ü
//------------------------------------------------------------------------------
#pragma pack(push, 1)
typedef struct 
{
	LANE_INFO sInfo;							//
	std::vector<__int64> vPrevLane;
	std::vector<__int64> vNextLane;
	std::vector<VERTEX_INFO> vGeometry;			// ����
} LANE_VTX;										// ����
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	PARKINGLOT_INFO sInfo;						// 
	std::vector<VERTEX_INFO> vGeometry;			// ����
} PARKINGLOT_VTX;								// ����
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	SIGN_INFO sInfo;							// 
	std::vector<VERTEX_INFO> vGeometry;			// 
} SIGN_VTX;										//  
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	LINE_INFO sInfo;							//
	std::vector<VERTEX_INFO> vGeometry;			// ����
} LINE_VTX;										// ����
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	CROSSWALK_INFO sInfo;						//
	std::vector<VERTEX_INFO> vGeometry;			// ����
} CROSSWALK_VTX;								// ����
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	SIGNAL_INFO sInfo;							// 
	VERTEX_INFO sGeometry;						// 24
} SIGNAL_VTX;									// 
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	BORDER_INFO sInfo;							// 
	std::vector<VERTEX_INFO> vGeometry;			// ����
} BORDER_VTX;									// ����
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	SPEEDBUMP_INFO sInfo;
	std::vector<VERTEX_INFO> vGeometry;
} SPEEDBUMP_VTX;
#pragma pack(pop)


//------------------------------------------------------------------------------
//			���� ������ ������ ����ü
//------------------------------------------------------------------------------
#pragma pack(push, 1)
typedef struct 
{
	__int64 nID;
	__int64 nJunctionID;
	std::vector<__int64> nPredecessorID;
	std::vector<__int64> nSuccessorID;
	double dLength;
	__int8 nLaneCnt;
	std::vector<LANE_VTX> vLanes;
	std::vector<LINE_VTX> vLines;
	std::vector<CROSSWALK_VTX> vCrosswalks;
	std::vector<SIGNAL_VTX> vSignals;
	std::vector<SIGN_VTX> vStopsigns;
	std::vector<SIGN_VTX> vYieldsigns;
	std::vector<SPEEDBUMP_VTX> vSpeedbumps;
} ROAD;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int8 nFrom;
	__int8 nTo;
} LANELINK;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int8 nID;
	__int64 nIncomingRoadID;
	__int64 nConnectingRoadID;
	__int8 nContactPoint;
	__int8 nType;
	std::vector<LANELINK> vLaneLinks;
} CONNECTION;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int64 nID;
	__int8	nType;
	std::vector<CONNECTION> vConnections;
} JUNCTION;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int64 nID;
	std::vector<ROAD> vRoads;
	std::vector<JUNCTION> vJunctions;						// ���� �Ϸ�
	std::vector<LINE_VTX> vStopLines;						// ���� �Ϸ�
	std::vector<BORDER_VTX> vBorders;						// ������ ������ ������ ����
	std::vector<PARKINGLOT_VTX> vParkinglots;				// ������ ������ ������ ����
	std::vector<CROSSWALK_VTX> vCrosswalks_out;				// ���� �Ϸ�
} LOCAL_MAP;
#pragma pack(pop)


//------------------------------------------------------------------------------
//			���Ἲ ���� ������ ����ü
//------------------------------------------------------------------------------
#pragma pack(push, 1)
typedef struct 
{
	int8_t				nIndex;
	int16_t				nDirection;
	int64_t				nID;
}RP_CONNECTION;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	int64_t				nID;						// ����ID (������)
	int8_t				nLaneIndex;					// ���� �ε���
	int8_t				nMaxSpeed;					// �ְ����Ѽӵ�
	//int8_t				nPrevLaneNum;				// ���� ���� ����
	//int8_t				nNextLaneNum;				// ���� ���� ���� 
	int16_t				nDirection;					// ���� ����
	int64_t				nR_LaneID;					// �������� ID (������)
	int64_t				nL_LaneID;					// �������� ID (������)
	float				fLength;					// ����
	double				dStartX;					// ���ؽ� ���� X ��ǥ
	double				dStartY;					// ���ؽ� ���� Y ��ǥ
	double				dEndX;						// ���ؽ� �� X ��ǥ
	double				dEndY;						// ���ؽ� �� Y ��ǥ
	std::vector<int64_t>	vLeftLine;				// ���� ���� ID ����Ʈ
	std::vector<int64_t>	vRightLine;				// ���� ���� ID ����Ʈ
	std::vector<RP_CONNECTION> vPrevLane;			// ���� ���� ID ����Ʈ
	std::vector<RP_CONNECTION> vNextLane;			// ���� ���� ID ����Ʈ
}LANE_CONNECTIVITY;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	int64_t				nID;						// ����ID (������)
	int16_t				nDirection;					// ������� (��/��ȸ��, ���� ��)
	int8_t				nMaxSpeed;					// �ְ����Ѽӵ�
	int8_t				nPrevRoadNum;				// ���� ���� ����
	int8_t				nNextRoadNum;				// ���� ���� ����
	int8_t				nLaneNum;					// ���Ե� ���� ����
	float				fLength;					// ����
	double				dStartX;					// ���ؽ� ���� X ��ǥ
	double				dStartY;					// ���ؽ� ���� Y ��ǥ
	double				dEndX;						// ���ؽ� �� X ��ǥ
	double				dEndY;						// ���ؽ� �� Y ��ǥ
	std::vector<RP_CONNECTION> vPrevRoad;
	std::vector<RP_CONNECTION> vNextRoad;
	std::vector<LANE_CONNECTIVITY> mLanes;
	//std::unordered_map<__int64, LANE_CONNECTIVITY> mLanes;
}ROAD_CONNECTIVITY;
#pragma pack(pop)

#if defined(SAVE_GRID_CONNECTIVITY)
#pragma pack(push, 1)
typedef struct 
{
	unsigned int		uID;						// �׸��� ID
	std::vector<ROAD_CONNECTIVITY> mRoads;
	//std::unordered_map<__int64, ROAD_CONNECTIVITY> mRoads;
}GRID_CONNECTIVITY;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct 
{
	__int64				nID;						// ���Ἲ ���� ID
	std::vector<GRID_CONNECTIVITY> mGrids;
	//std::unordered_map<unsigned int, GRID_CONNECTIVITY> mGrids;
}CONNECTIVITY;
#pragma pack(pop)
#else
#pragma pack(push, 1)
typedef struct 
{
	__int64				nID;						// ���Ἲ ���� ID
	std::vector<ROAD_CONNECTIVITY> mRoads;
	//std::unordered_map<__int64, ROAD_CONNECTIVITY> mRoads;
}CONNECTIVITY;
#pragma pack(pop)

#endif

#pragma pack(push, 1)
typedef struct 
{
	double dDestX;
	double dDestY;
	std::vector<unsigned int> vGrids;
}REQUEST_RP_TO_MDAL;
#pragma pack(pop)

#endif
