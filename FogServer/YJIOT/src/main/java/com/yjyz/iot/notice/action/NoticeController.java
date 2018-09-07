package com.yjyz.iot.notice.action;

import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.yjyz.iot.comm.ConstParm;
import com.yjyz.iot.comm.RetInfoDto;
import com.yjyz.iot.notice.dto.NoticeDto;
import com.yjyz.iot.notice.entity.NoticeConfig;
import com.yjyz.iot.notice.entity.NoticePush;
import com.yjyz.iot.notice.entity.NoticeRule;
import com.yjyz.iot.notice.service.INoticeService;
import com.yjyz.iot.security.utils.ClientJwtToken;
import com.yjyz.iot.security.utils.ClientJwtUtil;

/**
 * @class :PushController
 * @TODO :
 * @author:HeroLizhen
 * @date :2018年5月12日下午4:20:52
 */
@RestController
@RequestMapping("/notice")
public class NoticeController {
	private static Log log = LogFactory.getLog(NoticeController.class);
	@Autowired
	private INoticeService noticeService;
	@Autowired
	ClientJwtUtil jwtUtil;

	@Transactional
	@RequestMapping(value = "/addNoticeConfig", method = RequestMethod.POST)
	public RetInfoDto addNoticeConfig(@RequestBody NoticeConfig dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.insNoticeConfig(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_INSERT);
				info.meta.put("message", "addNoticeConfig fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "addNoticeConfig fail.");
			info.meta.put("code", ConstParm.ERR_INSERT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selNoticeConfig", method = RequestMethod.POST)
	public RetInfoDto selNoticeConfig(@RequestBody NoticeConfig dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			NoticeConfig noticeConfig = this.noticeService.selNoticeConfig(dto.getAppId());
			if (noticeConfig != null) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("NoticeConfig", noticeConfig);
			} else {
				info.meta.put("code", ConstParm.ERR_SELECT);
				info.meta.put("message", "selNoticeConfig fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selNoticeConfig fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/delNoticeConfig", method = RequestMethod.POST)
	public RetInfoDto delNoticeConfig(@RequestBody NoticeConfig dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.delNoticeConfig(dto.getAppId());
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_DELETE);
				info.meta.put("message", "delPushConfig fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "delPushConfig fail.");
			info.meta.put("code", ConstParm.ERR_DELETE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/updNoticeConfig", method = RequestMethod.POST)
	public RetInfoDto updNoticeConfig(@RequestBody NoticeConfig dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.updNoticeConfig(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_UPDATE);
				info.meta.put("message", "updNoticeConfig fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "updNoticeConfig fail.");
			info.meta.put("code", ConstParm.ERR_UPDATE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/addNoticeRule", method = RequestMethod.POST)
	public RetInfoDto addNoticeRule(@RequestBody NoticeRule dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.insNoticeRule(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_INSERT);
				info.meta.put("message", "addNoticeRule fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "addNoticeRule fail.");
			info.meta.put("code", ConstParm.ERR_INSERT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selNoticeRule", method = RequestMethod.POST)
	public RetInfoDto selNoticeRule(@RequestBody NoticeRule dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			NoticeRule noticeRule = this.noticeService.selNoticeRule(dto.getProductId());
			if (noticeRule != null) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("NoticeRule", noticeRule);
			} else {
				info.meta.put("code", ConstParm.ERR_SELECT);
				info.meta.put("message", "selNoticeRule fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selNoticeRule fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/delNoticeRule", method = RequestMethod.POST)
	public RetInfoDto delNoticeRule(@RequestBody NoticeRule dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.delNoticeRule(dto.getProductId());
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_DELETE);
				info.meta.put("message", "delNoticeRule fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "delNoticeRule fail.");
			info.meta.put("code", ConstParm.ERR_DELETE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/updNoticeRule", method = RequestMethod.POST)
	public RetInfoDto updNoticeRule(@RequestBody NoticeRule dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.updNoticeRule(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_UPDATE);
				info.meta.put("message", "updNoticeRule fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "updNoticeRule fail.");
			info.meta.put("code", ConstParm.ERR_UPDATE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/addNoticePush", method = RequestMethod.POST)
	public RetInfoDto addNoticePush(@RequestBody NoticePush dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.insNoticePush(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_INSERT);
				info.meta.put("message", "addNoticePush fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "addNoticePush fail.");
			info.meta.put("code", ConstParm.ERR_INSERT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selNoticePush", method = RequestMethod.POST)
	public RetInfoDto selNoticePush(@RequestBody NoticePush dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {

			NoticePush noticePush = this.noticeService.selNoticePush(dto.getProductId(), dto.getPushNo());
			if (noticePush != null) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
				info.data.put("NoticePush", noticePush);
			} else {
				info.meta.put("code", ConstParm.ERR_SELECT);
				info.meta.put("message", "selNoticePush fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selNoticePush fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/selNoticePushAll", method = RequestMethod.POST)
	public RetInfoDto selNoticePushAll(@RequestBody NoticePush dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			List<NoticePush> noticePushs = this.noticeService.selNoticePushAll(dto.getProductId());
			info.meta.put("code", ConstParm.SUCESS_CODE);
			info.data.put("NoticePush", noticePushs);

		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "selNoticePushAll fail.");
			info.meta.put("code", ConstParm.ERR_SELECT);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/delNoticePush", method = RequestMethod.POST)
	public RetInfoDto delNoticePush(@RequestBody NoticePush dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.delNoticePush(dto.getProductId(), dto.getPushNo());
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_DELETE);
				info.meta.put("message", "delNoticePush fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "delNoticePush fail.");
			info.meta.put("code", ConstParm.ERR_DELETE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/updNoticePush", method = RequestMethod.POST)
	public RetInfoDto updNoticePush(@RequestBody NoticePush dto, @RequestHeader String Authorization) {

		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}

		try {
			boolean isOk = this.noticeService.updNoticePush(dto);
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_UPDATE);
				info.meta.put("message", "updNoticePush fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "updNoticePush fail.");
			info.meta.put("code", ConstParm.ERR_UPDATE);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/noticeTest", method = RequestMethod.POST)
	public RetInfoDto noticeTest(@RequestBody NoticeDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		try {
			jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		try {
			boolean isOk = this.noticeService.noticeTest(dto.getAppId(), dto.getTel(), dto.getType());
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_NOTICE_NOTICETEST);
				info.meta.put("message", "noticeTest fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "noticeTest fail.");
			info.meta.put("code", ConstParm.ERR_NOTICE_NOTICETEST);
		}
		return info;
	}

	@Transactional
	@RequestMapping(value = "/pushTest", method = RequestMethod.POST)
	public RetInfoDto pushTest(@RequestBody NoticeDto dto, @RequestHeader String Authorization) {
		RetInfoDto info = new RetInfoDto();
		ClientJwtToken jwtToken;
		try {
			jwtToken = jwtUtil.parseToken(Authorization);
		} catch (Exception e) {
			info.meta.put("message", "access token is wrong!");
			info.meta.put("code", ConstParm.ERR_CODE_JWT);
			return info;
		}
		try {
			boolean isOk = this.noticeService.pushTest(jwtToken.getApp_id(), dto.getTel(), dto.getProductId(),
					dto.getPushNo());
			if (isOk) {
				info.meta.put("code", ConstParm.SUCESS_CODE);
			} else {
				info.meta.put("code", ConstParm.ERR_NOTICE_PUSHTEST);
				info.meta.put("message", "pushTest fail.");
			}
		} catch (Exception e) {
			log.error(e);
			info.meta.put("message", "pushTest fail.");
			info.meta.put("code", ConstParm.ERR_NOTICE_PUSHTEST);
		}
		return info;
	}

}
