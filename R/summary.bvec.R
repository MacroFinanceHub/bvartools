#' Summarising Bayesian VEC Coefficients
#'
#' summary method for class \code{"bvec"}.
#'
#' @param object an object of class \code{"bvec"}, usually, a result of a call to
#' \code{\link{bvec}}.
#' @param ci a numeric between 0 and 1 specifying the probability of the credible band.
#' Defaults to 0.95.
#' @param x an object of class \code{"summary.bvec"}, usually, a result of a call to
#' \code{\link{summary.bvec}}.
#' @param digits the number of significant digits to use when printing.
#' @param ... further arguments passed to or from other methods.
#'
#' @return \code{summary.bvec} returns a list of class \code{"summary.bvec"},
#' which contains the following components:
#' \item{coefficients}{A list of various summary statistics of the posterior
#' draws of the VAR coefficients.}
#' \item{sigma}{A list of various summary statistics of the posterior
#' draws of the variance-covariance matrix.}
#' \item{specifications}{a list containing information on the model specification.}
#'
#' @export
summary.bvec <- function(object, ci = .95, ...){
  # Number of endogenous variables
  k <- object$specifications$dims["K"]
  
  # Extract variable names
  dim_names <- list(NULL, NULL)
  if (!is.null(object$y)) {
    y_names <- dimnames(object$y)[[2]]
  } else {
    y_names <- paste("d.y", 1:k, sep = "")
  }
  
  # Extract names of ECT-variables
  w_names <- NULL
  if (!is.null(object[["Pi"]])) {
    if (!is.null(object[["w"]])) {
      w_names <- dimnames(object[["w"]])[[2]]
    } else {
      w_names <- paste("l.y", 1:k, ".l1", sep = "")
    } 
  }
  if (!is.null(object[["Pi_x"]])) {
    if (!is.null(object[["w_x"]])) {
      w_names <- c(w_names, dimnames(object[["w_x"]])[[2]])
    } else {
      if (!is.null(object[["P_x"]])) {
        w_names <- c(w_names, paste("l.x", 1:(NCOL(object[["P_x"]]) / k), ".l1", sep = ""))
      }
    } 
  }
  if (!is.null(object[["Pi_d"]])) {
    if (!is.null(object[["w_d"]])) {
      w_names <- c(w_names, dimnames(object[["w_d"]])[[2]])
    } else {
      if (!is.null(object[["Pi_d"]])) {
        w_names <- c(w_names, paste("l.det", 1:(NCOL(object[["Pi_d"]]) / k), ".l1", sep = ""))
      }
    } 
  }
  
  # Names of non-cointegration regressors
  x_names <- NULL
  if (!is.null(object[["x"]])) {
    x_names <- dimnames(object[["x"]])[[2]]
  } else {
    x_names <- NULL
    if (!is.null(object[["Gamma"]])) {
      m <- NCOL(object[["Gamma"]]) / k
      p <- m / k
      for (i in 1:p) {
        x_names <- c(x_names, paste(y_names, ".l", i, sep = ""))
      }
    }
  }
  if (!is.null(object[["x_x"]])) {
    x_names <- c(x_names, dimnames(object[["x_x"]])[[2]])
  } else {
    if (!is.null(object[["Upsilon"]])) {
      m <- NCOL(object[["Upsilon"]]) / k
      x_names <- c(x_names, paste("d.x", 1:m, sep = ""))
    }
  }
  if (!is.null(object[["x_d"]])) {
    x_names <- c(x_names, dimnames(object[["x_d"]])[[2]])
  } else {
    if (!is.null(object[["C"]])) {
      m <- NCOL(object[["C"]]) / k
      x_names <- c(x_names, paste("det", 1:m, sep = ""))
    }
  }
  if (!is.null(object[["A0"]])) {
    x_names <- c(x_names, y_names)
  }
  
  # Non-error coefficients
  means <- NULL
  median <- NULL
  sds <- NULL
  naive_sd <- NULL
  ts_sd <- NULL
  
  ci_low <- (1 - ci) / 2
  ci_high <- 1 - ci_low
  q_low <- NULL
  q_high <- NULL
  
  use_incl <- FALSE
  if (any(grepl("lambda", names(object)))) {
    use_incl <- TRUE
    incl <- NULL
  }
  
  vars <- c("Pi", "Pi_x", "Pi_d", "Gamma", "Upsilon", "C", "A0")
  for (i in vars) {
    if (!is.null(object[[i]])) {
      temp <- summary(object[[i]], quantiles = c(ci_low, .5, ci_high))
      if ("numeric" %in% class(temp$statistics)) {
        means <- cbind(means, matrix(temp$statistics["Mean"], k))
        sds <- cbind(sds, matrix(temp$statistics["SD"], k))
        naive_sd <- cbind(naive_sd, matrix(temp$statistics["Naive SE"], k))
        ts_sd <- cbind(ts_sd, matrix(temp$statistics["Time-series SE"], k))
        q_low <- cbind(q_low, matrix(temp$quantiles[1], k))
        median <- cbind(median, matrix(temp$quantiles[2], k))
        q_high <- cbind(q_high, matrix(temp$quantiles[3], k)) 
      } else {
        means <- cbind(means, matrix(temp$statistics[, "Mean"], k))
        sds <- cbind(sds, matrix(temp$statistics[, "SD"], k))
        naive_sd <- cbind(naive_sd, matrix(temp$statistics[, "Naive SE"], k))
        ts_sd <- cbind(ts_sd, matrix(temp$statistics[, "Time-series SE"], k))
        q_low <- cbind(q_low, matrix(temp$quantiles[, 1], k))
        median <- cbind(median, matrix(temp$quantiles[, 2], k))
        q_high <- cbind(q_high, matrix(temp$quantiles[, 3], k)) 
      }
      if (use_incl) {
        var_temp <- paste0(i, "_lambda")
        if (var_temp %in% names(object)) {
          incl <- cbind(incl, matrix(colMeans(object[[var_temp]]), k))
        } else {
          incl <- cbind(incl, matrix(rep(NA_real_, ncol(object[[i]])), k))
        }
      }
    }
  }
  
  if (!is.null(means)) {
    dim_names <- list(y_names, c(w_names, x_names))
    dimnames(means) <- dim_names
    dimnames(sds) <- dim_names
    dimnames(naive_sd) <- dim_names
    dimnames(ts_sd) <- dim_names
    dimnames(q_low) <- dim_names
    dimnames(median) <- dim_names
    dimnames(q_high) <- dim_names
  }
  
  result <- list(coefficients = list(means = means,
                                     median = median,
                                     sd = sds,
                                     naivesd = naive_sd,
                                     tssd = ts_sd,
                                     q_lower = q_low,
                                     q_upper = q_high))
  
  if (use_incl) {
    result$coefficients$lambda = incl
  }
  
  # Error coefficients
  dim_names <- list(y_names, y_names)
  
  if (!is.null(object[["Sigma"]])) {
    temp <- summary(object$Sigma, quantiles = c(ci_low, .5, ci_high))
    if (k == 1) {
      means <- matrix(temp$statistics["Mean"], k)
      sds <- matrix(temp$statistics["SD"], k)
      naive_sd <- matrix(temp$statistics["Naive SE"], k)
      ts_sd <- matrix(temp$statistics["Time-series SE"], k)
      q_low <- matrix(temp$quantiles[1], k)
      median <- matrix(temp$quantiles[2], k)
      q_high <- matrix(temp$quantiles[3], k)
    } else {
      means <- matrix(temp$statistics[, "Mean"], k)
      sds <- matrix(temp$statistics[, "SD"], k)
      naive_sd <- matrix(temp$statistics[, "Naive SE"], k)
      ts_sd <- matrix(temp$statistics[, "Time-series SE"], k)
      q_low <- matrix(temp$quantiles[, 1], k)
      median <- matrix(temp$quantiles[, 2], k)
      q_high <- matrix(temp$quantiles[, 3], k)
    }
    
    dimnames(means) <- dim_names
    dimnames(sds) <- dim_names
    dimnames(naive_sd) <- dim_names
    dimnames(ts_sd) <- dim_names
    dimnames(q_low) <- dim_names
    dimnames(median) <- dim_names
    dimnames(q_high) <- dim_names
    
    result$sigma <- list(means = means,
                         median = median,
                         sd = sds,
                         naivesd = naive_sd,
                         tssd = ts_sd,
                         q_lower = q_low,
                         q_upper = q_high)
    
    if ("Sigma_lambda" %in% names(object)) {
      incl <- diag(NA_real_, k)
      means <- colMeans(object$Sigma_lambda)
      incl[upper.tri(incl)] <- means
      incl[lower.tri(incl)] <- means
      dimnames(incl) <- dim_names
      result$sigma$lambda = incl
    }
  }
  
  result$specifications <- object$specifications
  result$specifications$ci <- paste(c(ci_low, ci_high) * 100, "%", sep = "")
  
  class(result) <- "summary.bvec"
  return(result)
}
