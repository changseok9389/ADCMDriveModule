#pragma once
#pragma pack(1)

#include "MapStructs.h"


namespace adcm {
	namespace hdmap {

#if defined (__linux__)
		//******************************************************************
		//		  ADCM HDMAP API
		//******************************************************************
		void setFilePath(const char* pPath);															// 파일 저장 디렉토리 경로 설정 기능
		const char* getFilePath();																		// 파일 저장 디렉토리 경로 반환 기능
		void clearLocalMap(LOCAL_MAP &sLocalMap);														// Local Map 요소 전체 삭제
		
		void requestMapDataInGrid_ID(int nGridID, LOCAL_MAP &sLocalMap);								// 파라미터로 전달된 Local Map 구조체에 지도 데이터 적재
		void requestMapDataInCell_ID(int nGridID, int nCellID, int nCnt, LOCAL_MAP &sLocalMap);			// 파라미터로 전달된 Local Map 구조체에 지도 데이터 적재

		void transWGStoUTM(double* pX_out, double* pY_out, double* pLon_in, double* pLat_in);			// WGS84 -> UTM52N
		void transUTMtoWGS(double* pX_in, double* pY_in, double* pLon_out, double* pLat_out);			// UTM52N -> WGS84

		int requestGridID_WGS84(double dLongitude, double dLatitude);									// 좌표값이 위치한 그리드 ID 계산(WGS84)
		int requestGridID_UTM52N(double dX, double dY);													// 좌표값이 위치한 그리드 ID 계산(UTM52N)
		int requestCellID_WGS84(double dLongitude, double dLatitude); 									// 좌표값이 위치한 셀 ID 계산(WGS84)
		int requestCellID_UTM52N(double dX, double dY);													// 좌표값이 위치한 셀 ID 계산(UTM52N)

		void searchObjectInGrid(int nGridID, __int64 nObjectID, LANE_VTX &sInfo);						// 동작 x, 차로 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SPEEDBUMP_VTX &sInfo);					// 동작 x, 과속방지턱 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, LINE_VTX &sInfo);						// 동작 x, 차선 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, CROSSWALK_VTX &sInfo);					// 동작 x, 횡단보도 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SIGNAL_VTX &sInfo);						// 동작 x, 신호등 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SIGN_VTX &sInfo);						// 동작 x, 표지판 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, BORDER_VTX &sInfo);						// 동작 x, 안전방호시설 정보 검색 기능
		void searchObjectInGrid(int nGridID, __int64 nObjectID, PARKINGLOT_VTX &sInfo);					// 동작 x, 주차장 정보 검색 기능

		void clearConnectivity(CONNECTIVITY &sConnectivity);											// 동작 x, 경로 탐색용 네트워크 데이터 전체 삭제
		void requestConnectivityInfo_WGS84(REQUEST_RP_TO_MDAL sRpToMDAL, CONNECTIVITY &sConnectivity);	// 동작 x, WGS84 이용 경로 탐색용 네트워크 데이터 추출
		void requestConnectivityInfo_UTM52N(REQUEST_RP_TO_MDAL sRpToMDAL, CONNECTIVITY &sConnectivity);	// 동작 x, UTM52N 이용 경로 탐색용 네트워크 데이터 추출
		void requestConnectivityInfo(std::vector<unsigned int> &vGrids, CONNECTIVITY &sConnectivity);	// 동작 x, 그리드 ID 이용 경로 탐색용 네트워크 데이터 추출
		void requestAllGridIDList(std::vector<unsigned int> &vGridIDList);								// 동작 x, 로딩한 맵 파일 내 모든 그리드 ID 추출
#endif
	}
}


