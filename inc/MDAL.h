#pragma once
#pragma pack(1)

#include "MapStructs.h"


namespace adcm {
	namespace hdmap {

#if defined (__linux__)
		//******************************************************************
		//		  ADCM HDMAP API
		//******************************************************************
		void setFilePath(const char* pPath);															// ���� ���� ���丮 ��� ���� ���
		const char* getFilePath();																		// ���� ���� ���丮 ��� ��ȯ ���
		void clearLocalMap(LOCAL_MAP &sLocalMap);														// Local Map ��� ��ü ����
		
		void requestMapDataInGrid_ID(int nGridID, LOCAL_MAP &sLocalMap);								// �Ķ���ͷ� ���޵� Local Map ����ü�� ���� ������ ����
		void requestMapDataInCell_ID(int nGridID, int nCellID, int nCnt, LOCAL_MAP &sLocalMap);			// �Ķ���ͷ� ���޵� Local Map ����ü�� ���� ������ ����

		void transWGStoUTM(double* pX_out, double* pY_out, double* pLon_in, double* pLat_in);			// WGS84 -> UTM52N
		void transUTMtoWGS(double* pX_in, double* pY_in, double* pLon_out, double* pLat_out);			// UTM52N -> WGS84

		int requestGridID_WGS84(double dLongitude, double dLatitude);									// ��ǥ���� ��ġ�� �׸��� ID ���(WGS84)
		int requestGridID_UTM52N(double dX, double dY);													// ��ǥ���� ��ġ�� �׸��� ID ���(UTM52N)
		int requestCellID_WGS84(double dLongitude, double dLatitude); 									// ��ǥ���� ��ġ�� �� ID ���(WGS84)
		int requestCellID_UTM52N(double dX, double dY);													// ��ǥ���� ��ġ�� �� ID ���(UTM52N)

		void searchObjectInGrid(int nGridID, __int64 nObjectID, LANE_VTX &sInfo);						// ���� x, ���� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SPEEDBUMP_VTX &sInfo);					// ���� x, ���ӹ����� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, LINE_VTX &sInfo);						// ���� x, ���� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, CROSSWALK_VTX &sInfo);					// ���� x, Ⱦ�ܺ��� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SIGNAL_VTX &sInfo);						// ���� x, ��ȣ�� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, SIGN_VTX &sInfo);						// ���� x, ǥ���� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, BORDER_VTX &sInfo);						// ���� x, ������ȣ�ü� ���� �˻� ���
		void searchObjectInGrid(int nGridID, __int64 nObjectID, PARKINGLOT_VTX &sInfo);					// ���� x, ������ ���� �˻� ���

		void clearConnectivity(CONNECTIVITY &sConnectivity);											// ���� x, ��� Ž���� ��Ʈ��ũ ������ ��ü ����
		void requestConnectivityInfo_WGS84(REQUEST_RP_TO_MDAL sRpToMDAL, CONNECTIVITY &sConnectivity);	// ���� x, WGS84 �̿� ��� Ž���� ��Ʈ��ũ ������ ����
		void requestConnectivityInfo_UTM52N(REQUEST_RP_TO_MDAL sRpToMDAL, CONNECTIVITY &sConnectivity);	// ���� x, UTM52N �̿� ��� Ž���� ��Ʈ��ũ ������ ����
		void requestConnectivityInfo(std::vector<unsigned int> &vGrids, CONNECTIVITY &sConnectivity);	// ���� x, �׸��� ID �̿� ��� Ž���� ��Ʈ��ũ ������ ����
		void requestAllGridIDList(std::vector<unsigned int> &vGridIDList);								// ���� x, �ε��� �� ���� �� ��� �׸��� ID ����
#endif
	}
}


