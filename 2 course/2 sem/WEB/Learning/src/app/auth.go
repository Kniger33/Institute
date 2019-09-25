package app

import (
	"../models"
	"../utils"
	"fmt"
	"net/http"
)

func InfoHandler(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	claims := r.Context().Value("user").(*models.Claims)
	data := fmt.Sprintf("Your nickname: %v", claims.Nickname)
	response := models.BaseResponse{
		Status: true,
		Data:   data,
	}
	utils.Respond(w, r, response)
}
