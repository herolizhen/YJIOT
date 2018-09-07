package com.yjyz.iot.ota.service.impl;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.util.Date;
import java.util.List;
import java.util.UUID;

import javax.annotation.Resource;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import com.yjyz.iot.ota.dao.OTAFileInfoMapper;
import com.yjyz.iot.ota.entity.OTAFileInfo;
import com.yjyz.iot.ota.service.IOTAFileService;
import com.yjyz.iot.ota.util.MD5Util;

/**
 * @class :OTAFileServiceImpl
 * @TODO :
 * @author:HeroLizhen
 * @date :2017年11月28日上午10:35:34
 */
@Service("otaFileService")
public class OTAFileServiceImpl implements IOTAFileService {

	@Resource
	OTAFileInfoMapper OTAFileInfoDao;
	@Value("${cfg.sys.otafile.filePath}")
	private String OTAFILEPATH;

	@Value("${cfg.sys.otafile.urlPath}")
	private String OTAFILEURL;

	@Override
	public List<OTAFileInfo> selectByProduceId(String produceId) throws Exception {
		return this.OTAFileInfoDao.selectByProductId(produceId);
	}

	@Override
	public boolean deleteByPrimaryKey(Integer id) throws Exception {
		OTAFileInfo fileInfo = this.OTAFileInfoDao.selectByPrimaryKey(id);
		if (fileInfo == null) {
			return false;
		}
		int ret = this.OTAFileInfoDao.deleteByPrimaryKey(id);
		if (ret != 1) {
			return true;
		}
		String fileName = "/";
		if (fileInfo.getFileurl() == null) {
			return true;
		}
		String fileNameTemp[] = fileInfo.getFileurl().split("/");
		fileName = fileName + fileNameTemp[fileNameTemp.length - 1];

		String filePath = OTAFILEPATH + "/" + fileInfo.getProductId();
		File file = new File(filePath);
		file = new File(filePath + fileName);
		if (file.exists()) {
			file.delete();
		}
		return true;
	}

	@Override
	public OTAFileInfo insert(OTAFileInfo record, MultipartFile multipartFile) throws Exception {

		String fileName = "/" + multipartFile.getOriginalFilename();
		String filePath = OTAFILEPATH + "/" + record.getProductId();
		File file = new File(filePath);
		if (!file.exists()) {
			file.mkdirs();
		}
		file = new File(filePath + fileName);
		if (file.exists()) {
			file.delete();
		}
		BufferedOutputStream buff = new BufferedOutputStream(new FileOutputStream(file));
		buff.write(multipartFile.getBytes());
		buff.close();
		String uploadMd5Code = MD5Util.getFileMD5String(file);
		record.setMd5(uploadMd5Code);
		int maxId = this.OTAFileInfoDao.getOTAFileInofMaxId();
		record.setId(maxId + 1);
		record.setOtaId(UUID.randomUUID().toString());
		record.setFileurl(OTAFILEURL + "/" + record.getProductId() + fileName);
		record.setUploadTime(new Date());
		int ret = this.OTAFileInfoDao.insertSelective(record);
		if (ret == 1) {
			return record;
		} else {
			return null;
		}
	}

	@Override
	public boolean updateByPrimaryKey(OTAFileInfo record, MultipartFile multipartFile) throws Exception {

		if (multipartFile.getOriginalFilename().length() > 0) {
			String fileName = "/" + multipartFile.getOriginalFilename();
			String filePath = OTAFILEPATH + "/" + record.getProductId();
			File file = new File(filePath);
			if (!file.exists()) {
				file.mkdirs();
			}
			file = new File(filePath + fileName);
			if (file.exists()) {
				file.delete();
			}
			BufferedOutputStream buff = new BufferedOutputStream(new FileOutputStream(file));
			buff.write(multipartFile.getBytes());
			buff.close();
			String uploadMd5Code = MD5Util.getFileMD5String(file);
			record.setMd5(uploadMd5Code);
			record.setFileurl(OTAFILEURL + "/" + record.getProductId() + fileName);
			record.setUploadTime(new Date());
		}
		int ret = this.OTAFileInfoDao.updateByPrimaryKeySelective(record);
		if (ret != 1) {
			return false;
		}
		return true;
	}

	@Override
	public OTAFileInfo selectByPrimaryKey(Integer id) throws Exception {
		return this.OTAFileInfoDao.selectByPrimaryKey(id);
	}
}
