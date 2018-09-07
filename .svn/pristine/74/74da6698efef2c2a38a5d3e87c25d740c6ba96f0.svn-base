package com.yjyz.iot.ota.service;

import java.util.List;

import org.springframework.web.multipart.MultipartFile;

import com.yjyz.iot.ota.entity.OTAFileInfo;

public interface IOTAFileService {
	OTAFileInfo selectByPrimaryKey(Integer id) throws Exception;

	boolean updateByPrimaryKey(OTAFileInfo record,MultipartFile multipartFile) throws Exception;

	List<OTAFileInfo> selectByProduceId(String produceId) throws Exception;

	boolean deleteByPrimaryKey(Integer id) throws Exception;

	OTAFileInfo insert(OTAFileInfo record,MultipartFile file) throws Exception;
	
}
