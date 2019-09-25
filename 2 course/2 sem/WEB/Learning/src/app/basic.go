package app

import (
	"../models"
	"../utils"
	"net/http"
)

func HomeHandler(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	response := models.BaseResponse{
		Data:   "Home page",
		Status: true,
	}
	utils.Respond(w, r, response)
}
