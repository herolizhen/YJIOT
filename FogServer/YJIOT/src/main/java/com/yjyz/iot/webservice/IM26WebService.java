package com.yjyz.iot.webservice;

import javax.jws.WebParam;
import javax.jws.WebService;

@WebService
public interface IM26WebService {
	int add(@WebParam(name = "firstA") int a, @WebParam(name = "firstB") int b);
}