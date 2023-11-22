package com.example.servingwebcontent;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import javax.servlet.http.HttpSession;
import java.util.LinkedList;
import java.util.List;

@Controller
public class GreetingController {

	@GetMapping("/greeting")
	public String greeting(@RequestParam(name = "name", required = false, defaultValue = "World") String name, Model model, HttpSession session) {
		System.out.println("SESSION TEST Attribute " + session.getAttribute("x"));
		List<String> allNames = (List<String>) session.getAttribute("allNames");

		if(allNames == null) {
			allNames = new LinkedList<String>();
			session.setAttribute("allNames", allNames);
		}

		allNames.add(name);

		model.addAttribute("name", name);
		model.addAttribute("allNames", allNames.toString());
		return "greeting";
	}

	@PostMapping("/atendimento")
	public String atendimento(@RequestParam(name = "name", required = false, defaultValue = "World") String name, Model model) {
		model.addAttribute("name", name);
		System.out.println("RECEBEMOS: " + name);
		return "atendimento";
	}
}
